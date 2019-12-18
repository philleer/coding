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

class Solution {
public:	
	// 19. Remove Nth Node From End of List
	/*=====================================================================
	 * Description: Given a linked list, remove the n-th node from the end
	 *	of list and return its head.
	 *
	 * Example:
	 *	Given linked list: 1->2->3->4->5, and n = 2.
	 *	After removing the second node from the end, the linked list
	 *	becomes 1->2->3->5.
	 *
	 * Note:
	 *	Given n will always be valid.
	 * Follow up:
	 *	Could you do this in one pass?
	 *=====================================================================
	 */
	// Definition for singly-linked list.
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr || n <= 0) return nullptr;
		
		ListNode *pNode1 = head;
		ListNode *pNode2 = head;
		if (n==1 && pNode1->next==nullptr) return nullptr;
		
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (pNode1->next != nullptr) {
				pNode1 = pNode1->next;
				++count;
			}
		}
		
		if (count == n-1) {
			head = pNode2->next;
			delete pNode2;
			return head;
		}
		
		while (pNode1->next != nullptr) {
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}

		ListNode *tmpNode = pNode2->next;
		pNode2->next = tmpNode->next;
		delete tmpNode;
		
		return head;
	}
};

void trimLeftTrailingSpaces(std::string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(),
			[](int ch) { return !isspace(ch); }
		));
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

int stringToInteger(std::string input) { return std::stoi(input); }

std::string listNodeToString(ListNode* node) {
	if (node == nullptr) return "[]";

	std::string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		ListNode* head = stringToListNode(line);
		std::getline(std::cin, line);
		int n = stringToInteger(line);
        
		ListNode* ret = Solution().removeNthFromEnd(head, n);

		std::string out = listNodeToString(ret);
		std::cout << out << std::endl;
	}
	
	return 0;
}
