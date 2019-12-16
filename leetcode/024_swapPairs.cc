/******************************************************************************
 * The source is part of my coding practice, a lightweight C++ solution for
 * leetcode program practice.
 *
 * For all of my code, after check it online by submit, I also compile and run
 * it by my offline machine
 * ============================================================================
 * ////////////// Microsoft Visual Studio 2010 when I use windows /////////////
 * //////////////           G++5.4.0 when I am on Linux           /////////////
 * ============================================================================
 *
 * If any question, feel free to send me an email << phillee2016@163.com >>
 * or just correct it via Pull Request or create an issue.
 ******************************************************************************
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
        // 24. Swap Nodes in Pairs
        /*=====================================================================
         * Description: Given a linked list, swap every two adjacent nodes and
         *      return its head.
         *      You may not modify the values in the list's nodes, only nodes
         *      itself may be changed.
         *
         * Example:
         *      Input: 1->2->3->4
         *      Output: 2->1->4->3
         *=====================================================================
         */
        ListNode* swapPairs(ListNode* head) {
                if (head == nullptr) return nullptr;

                ListNode* newHead = new ListNode(-1);
                newHead->next = head;
                ListNode* preNode = newHead;
                ListNode* curNode = preNode->next;
                while (curNode != nullptr && curNode->next != nullptr) {
                        preNode->next = curNode->next;
                        curNode->next = curNode->next->next;
                        curNode->next->next = curNode;            
                        preNode = preNode->next->next;
                        curNode = curNode->next;
                }

                return newHead->next;
        }

        ListNode* swapPairs2(ListNode* head) {
                if (head == nullptr) return nullptr;
                
                ListNode* newHead = new ListNode(-1);
                newHead->next = head;
                ListNode* preNode = newHead;
                ListNode* curNode = preNode->next;
                while (curNode != nullptr && curNode->next != nullptr) {
                        ListNode* nextNode = curNode->next;
                        preNode->next = nextNode;
                        curNode->next = nextNode->next;
                        nextNode->next = curNode;
                        preNode = nextNode->next;
                        curNode = curNode->next;
                }
                
                return newHead->next;
        }
};

void trimLeftTrailingSpaces(std::string &input) {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(std::string &input) {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
        }).base(), input.end());
}

std::vector<int> stringToIntegerVector(std::string input) {
        std::vector<int> output;
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        std::stringstream ss;
        ss.str(input);
        std::string item;
        char delim = ',';
        while (std::getline(ss, item, delim)) {
                output.push_back(std::stoi(item));
        }
        return output;
}

ListNode* stringToListNode(std::string input) {
        // Generate list from the input
        std::vector<int> list = stringToIntegerVector(input);

        // Now convert that list into linked list
        ListNode* dummyRoot = new ListNode(0);
        ListNode* ptr = dummyRoot;
        for(int item : list) {
                ptr->next = new ListNode(item);
                ptr = ptr->next;
        }
        ptr = dummyRoot->next;
        delete dummyRoot;
        return ptr;
}

std::string listNodeToString(ListNode* node) {
        if (node == nullptr) return "[]";

        std::string result;
        while (node) {
                result += std::to_string(node->val) + ", ";
                node = node->next;
        }
        return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
        std::string line;
        while (std::getline(std::cin, line)) {
                ListNode* head = stringToListNode(line);
                ListNode* ret = Solution().swapPairs(head);
                std::string out = listNodeToString(ret);
                std::cout << out << std::endl;
        }
    
        return 0;
}
