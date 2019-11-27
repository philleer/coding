/******************************************************************************
 * The source is part of my coding practice, a lightweight C++ solution for
 * leetcode program practice.
 *
 * For all of my code, after check it online by submit, I also compile and run
 * it by my offline machine
 * ============================================================================
 * ////////////// Microsoft Visual Studio 2010 when I use windows /////////////
  //////////////            G++5.4.0 when I am on Linux           /////////////
 * ============================================================================
 *
 * If any question, feel free to send me an email << phillee2016@163.com >>
 * or just correct it via Pull Request or create an issue.
 ******************************************************************************
 */
#include <iostream>
#include <vector>

// 707. Design Linked List
/*=========================================================================
 * Description: Design your implementation of the linked list. You can
 *  choose to use the singly linked list or the doubly linked list. A node
 *  in a singly linked list should have two attributes: val and next.
 *  val is the value of the current node, and next is a pointer to the next
 *  node. If you want to use the doubly linked list, you will need one more
 *  attribute prev to indicate the previous node in the linked list. Assume
 *  all nodes in the linked list are 0-indexed.
 *
 *  Implement these functions in your linked list class:
 *	get(index) : Get the value of the index-th node in the linked list.
 *		If the index is invalid, return -1.
 *	addAtHead(val) : Add a node of value val before the first element of
 *		the linked list. After the insertion, the new node will be
 *		the first node of the linked list.
 *	addAtTail(val) : Append a node of value val to the last element of
 *		the linked list.
 *	addAtIndex(index, val) : Add a node of value val before the index-th
 *		node in the linked list. If index equals to the length of
 *		linked list, the node will be appended to the end of linked
 *		list. If index is greater than the length, the node will not
 *		be inserted.
 *	deleteAtIndex(index) : Delete the index-th node in the linked list,
 *		if the index is valid. 
 *
 * Example:
 *	Input: ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", 
 *		"deleteAtIndex","get"]
 *	       [[],[1],[3],[1,2],[1],[1],[1]]
 *	Output: [null,null,null,null,2,null,3]
 *	Explanation: MyLinkedList linkedList = new MyLinkedList(); 
 *		// Initialize empty LinkedList
 *		linkedList.addAtHead(1);
 *		linkedList.addAtTail(3);
 *		linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
 *		linkedList.get(1);	      // returns 2
 *		linkedList.deleteAtIndex(1);  // now the linked list is 1->3
 *		linkedList.get(1);            // returns 3
 *
 * Constraints:
 *	0 <= index, val <= 1000;
 *	Please do not use the built-in LinkedList library.
 *	At most 2000 calls will be made to get, addAtHead, addAtTail,
 *	addAtIndex and deleteAtIndex.
 *=========================================================================
 */
class Node {
public:
	int val;
	Node *next;
	Node() { next = nullptr; }
	Node(int _val):val(_val),next(nullptr){}
};

class MyLinkedList {
private:
	Node *head;
	Node *tail;
	int size;

public:
	/*
	* Initialize your data structure here.
	*/
	MyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
    
	/*
	* Get the value of the index-th node in the linked list. If the
	* index is invalid, return -1.
	*/
	int get(int index) {
		if (index < 0 || index > size - 1) return -1;

		Node *current = head;
		for (int i = 0; i < index; i++)
			current = current->next;
		return current->val;
	}
    
	/*
	* Add a node of value val before the first element of the linked
	* list. After the insertion, the new node will be the first node
	* of the linked list.
	*/
	void addAtHead(int val) {
		Node *newNode = new Node(val);
		newNode->next = head;
		head = newNode;
		size++;

		if (tail == nullptr) tail = head;
	}
    
	/*
	* Append a node of value val to the last element of the linked list.
	*/
	void addAtTail(int val) {
		if (tail == nullptr) {
			head = tail = new Node(val);
		} else {
			tail->next = new Node(val);
			tail = tail->next;
		}
		size++;
	}
    
	/*
	* Add a node of value val before the index-th node in the linked
	* list. If index equals to the length of linked list, the node will
	* be appended to the end of linked list. If index is greater than
	* the length, the node will not be inserted.
	*/
	void addAtIndex(int index, int val) {
		if (index < 0) return;

		if (index == 0) {
			addAtHead(val);
		} else {
			if (index <= size) {
				if(index == size) {
					tail->next = new Node(val);
					tail = tail->next;
				} else {
					Node *current = head;
					for (int i = 1; i < index; i++)
						current = current->next;
					Node *temp = current->next;
					current->next = new Node(val);
					(current->next)->next = temp;
				}
				size++;
			}
		}
	}
    
	/*
	* Delete the index-th node in the linked list, if the index is valid.
	*/
	void deleteAtIndex(int index) {
		if (index < 0 || index > size -1) return;
		if (index == 0) {
			if (size == 0) return;

			head = head->next;
			if (head == nullptr) tail = nullptr;
			size--;
		} else {
			if (index == size - 1) {
				if (size == 1) {
					head = tail = nullptr;
					size = 0;
				} else {
					Node *current = head;
					for (int i = 1; i < index; i++)
						current = current->next;
					Node *temp = tail;
					tail = current;
					tail->next = nullptr;
					size--;
					delete temp;
				}
			} else {
				Node *previous = head;
				for (int i = 1; i < index; i++)
					previous = previous->next;
				Node *temp = previous->next;
				previous->next = (previous->next)->next;
				size--;
				delete temp;
			}
		}
	}
};

int main(int argc, char *argv[]) {
	MyLinkedList* obj = new MyLinkedList();
 	int param_1 = obj->get(index);
 	for (int i = 0; i < 5; ++i) obj->addAtHead(i);
 	for (int i = 0; i < 3; ++i) obj->addAtTail(i);

 	obj->addAtIndex(5, 12);
 	obj->deleteAtIndex(5);

	return 0;
}
