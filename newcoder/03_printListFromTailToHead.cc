// This file is part of my coding practice, a lightweight C++
// solution for newcoder program practice.
//
// For all of files in the coding folder, I check the rightness
// not only by the case test online, but also by my offline IDE
// Microsoft Visual Studio 2010 as well when I write on windows
// 7 64-bit platform or by g++5.4 when I am on linux platform.
// 
// If there are some questions, please send me an email: 
// Phil <phillee2016@163.com> or feel free to create an issue.

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x): val(x), next(NULL) {}
};

// typedef struct ListNode ListNode;

class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList &list);
	virtual ~LinkedList();

	void add(int element);
	void remove(int element);
	void clear();
	int getSize() const;
	bool isEmpty() const;
	ListNode* headPtr() const;

private:
	ListNode *head;
	int size;
};

LinkedList::LinkedList() {
	head = nullptr;
	size = 0;
}

LinkedList::LinkedList(const LinkedList &list) {
	head = nullptr;
	size = 0;
	ListNode *current = list.head;
	while (current != nullptr) {
		this->add(current->element);
		current = current->next;
	}
}

LinkedList::~LinkedList() {
	clear();
}

void LinkedList::add(int element) {
	if (head == nullptr) {
		head = new ListNode(element);
		printf("\tadd ListNode: %p->%d\n", head, head->val);
	}
	else {
		ListNode *pNode = head;
		while (pNode->next != nullptr) {
			pNode = pNode->next;
		}
		pNode->next = new ListNode(element);
		printf("\tadd ListNode: %p->%d\n", pNode->next, pNode->next->val);
	}
	size++;
}

void LinkedList::remove(int element) {
	ListNode *pNode = head;
	// 要删除的结点位于链表头
	if (pNode->val == element) {
		head = head->next;
		delete pNode;
		pNode = nullptr;
	}
	else {
		while (pNode != nullptr) {
			if (pNode->next->val == element)
				break;
			pNode = pNode->next;
		}
		ListNode *temp = pNode->next;
		pNode->next = pNode->next->next;
		delete temp;
		temp = nullptr;
	}
	size--;
}

void LinkedList::clear() {
	while (head != nullptr) {
		ListNode *temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	size = 0;
}

int LinkedList::getSize() const {
	return size;
}

bool LinkedList::isEmpty() const {
	return head == nullptr;
}

ListNode* LinkedList::headPtr() const {
	return head;
}

class Solution {
public:
	/*=============================================================
	 * 题目描述: 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList
	 * 例如: 	输入单链表1->2->3->4->5
	 *			返回顺序为5->4->3->2->1
	 *=============================================================
	 */
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head == nullptr)
            return {};
        stack<ListNode*> list;
        
        while (head != nullptr) {
            list.push(head);
            head = head->next;
        }
        
        vector<int> res;
        while (!list.empty()) {
            res.push_back(list.top()->val);
            list.pop();
        }
        return res;
    }
};

int main(int argc, char **argv) {

	LinkedList listTest;
	for (int i = 0; i < 5; i++)
		listTest.add(i);

	ListNode *temp = listTest.headPtr();
	printf("Original LinkedList:\n\t");
	while (temp != nullptr) {
		printf("%d\t", temp->val);
		temp = temp->next;
	}
	printf("\n");

	Solution solver;
	vector<int> vectorTest = solver.printListFromTailToHead(listTest.headPtr());
	printf("After reverse:\n\t");
	for (int i = 0; i < vectorTest.size(); i++) {
		printf("%d\t", vectorTest[i]);
	}
	printf("\n");

	return 0;
}