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
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

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
	// 83. Remove Duplicates from Sorted List
	/*=====================================================================
	 * Description: Given a sorted linked list, delete all duplicates such
	 *	that each element appear only once.
	 *
	 * Example:
	 *	Input: 1->1->2		Output: 1->2
	 *
	 *	Input: 1->1->2->3->3 	Output: 1->2->3
	 *=====================================================================
	 */
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;
		ListNode* curNode = dummyHead;
		while (curNode->next != nullptr) {
			ListNode* tmpNode = curNode->next;
			if (tmpNode == head) {
				curNode = tmpNode;
				continue;
			}
			
			if (curNode->val == tmpNode->val) {
				curNode->next = tmpNode->next;
				delete tmpNode;
				tmpNode = nullptr;
			} else {
				curNode = tmpNode;
			}
		}

		return dummyHead->next;
	}
};

// 下面的几个函数均为Leetcode官方测试代码中的实现，用于Debug，非常值得借鉴
void trimLeftTrailingSpaces(std::string &input) {
	input.erase(input.begin(), std::find_if(input.begin(), input.end(),
		[](int ch) { return !isspace(ch); }
	));
}

void trimRightTrailingSpaces(std::string &input) {
	input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
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
	if (node == nullptr) {
		return "[]";
	}
	
	std::string result;
	while (node) {
		result += std::to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		ListNode* head = stringToListNode(line);

		ListNode* ret = Solution().deleteDuplicates(head);
		std::string out = listNodeToString(ret);
		std::cout << out << std::endl;
	}

	return 0;
}


