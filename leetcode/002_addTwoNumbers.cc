// The source is part of my coding practice, a lightweight C++
// solution for leetcode program practice.
//
// For all of my code, after check it online by submit, I also compile
// and run it by my offline IDE 
// ===================================================================
// ********* Microsoft Visual Studio 2010 when I use windows *********
// *********           G++5.4.0 when I am on Linux           *********
// ===================================================================
//
// If any question, feel free to send me an email
// phillee2016@163.com
// or just correct it via Pull Request.

#include <iostream>
#include <cstdio>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /*==============================================================
     * You are given two non-empty linked lists representing two
     * non-negative integers. The digits are stored in reverse order
     * and each of their nodes contain a single digit. Add the two
     * numbers and return it as a linked list. You may assume the
     * two numbers do not contain any leading zero, except 0 itself.
     * Example:     Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
     *              Output: 7 -> 0 -> 8
     * Explanation: 342 + 465 = 807.
     *==============================================================
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        
        char carry = 0;
        ListNode *pNode1 = l1;
        ListNode *pNode2 = l2;        
        ListNode *pNode = new ListNode(carry);
        ListNode *head = pNode;
        
        for (; pNode1 != nullptr || pNode2 != nullptr;) {
            int val1 = pNode1 == nullptr ? 0 : pNode1->val;
            int val2 = pNode2 == nullptr ? 0 : pNode2->val;
            pNode->next = new ListNode((val1 + val2 +carry) % 10);
            carry = (val1 + val2 + carry) / 10;
            
            pNode1 = pNode1 == nullptr ? nullptr : pNode1->next;
            pNode2 = pNode2 == nullptr ? nullptr : pNode2->next;
            
            pNode = pNode->next;
        }
        
        if (carry) {
            pNode->next = new ListNode(carry);
        }
        
        return head->next;
    }
};

int main(int argc, char **argv) {
    ListNode* l1 = new ListNode(5);
	ListNode *head1 = l1;
	l1->next = new ListNode(4);
	l1 = l1->next;
	l1->next = new ListNode(5);

	ListNode* l2 = new ListNode(5);
	ListNode *head2 = l2;
	l2->next = new ListNode(6);
	l2 = l2->next;
	l2->next = new ListNode(5);

	ListNode *tmp = head1;
	printf("the first linked list is shown as:\n\t");
	while (tmp != nullptr) {
		printf("%d\t", tmp->val);
		tmp = tmp->next;
	}

	printf("\nthe second linked list is shown as:\n\t");
	tmp = head2;
	while (tmp != nullptr) {
		printf("%d\t", tmp->val);
		tmp = tmp->next;
	}

	Solution solver;
    ListNode *res = solver.addTwoNumbers(head1, head2);
	printf("\nthe result linked list is shown as:\n\t");
	tmp = res;
	while (tmp != nullptr) {
		printf("%d\t", tmp->val);
		tmp = tmp->next;
	}

    return 0;
}
