<<<<<<< HEAD
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
=======
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
// or just correct it via Pull Request ^_^

>>>>>>> 630b80c... add solution for merging two sorted lists
#include <iostream>
#include <csdtio>

using namespace std;

/**
 * Definition for singly-linked list.
<<<<<<< HEAD
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/*===========================================================================
	 * Difficuty level:	Easy
	 * Desciption: 	Merge two sorted linked lists and return a new list. The new
	 * 		list should be made by splicing together the nodes of the first 2 lists.
	 * Example:
   *    Input: 1->2->4, 1->3->4	   	Output: 1->1->2->3->4->4
	 *===========================================================================
	 */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ((l1 == nullptr) && (l2 == nullptr)) return nullptr;
        else if ((l1 == nullptr) && (l2 != nullptr)) return l2;
        else if ((l1 != nullptr) && (l2 == nullptr)) return l1;
=======
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
	/*==============================================================  
	 * Difficuty level:	Easy
	 * Desciption: 	Merge two sorted linked lists and return a new 
	 * 				list. The new list should be made by splicing 
	 * 				together the nodes of the first two lists.
	 * Example: 	Input: 1->2->4, 1->3->4
	 *	   			Output: 1->1->2->3->4->4
	 *==============================================================  
	 */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ((l1 == nullptr) && (l2 == nullptr))
            return nullptr;
        else if ((l1 == nullptr) && (l2 != nullptr))
            return l2;
        else if ((l1 != nullptr) && (l2 == nullptr))
            return l1;
>>>>>>> 630b80c... add solution for merging two sorted lists
        else {
            ListNode *res = new ListNode(0);
            ListNode *pNode = res;
            ListNode *ptr_l1 = l1;
            ListNode *ptr_l2 = l2;
            
            while (l1 != nullptr && l2 != nullptr) {
                if (l1->val > l2->val) {
                    res->next = new ListNode(l2->val);
                    res = res->next;
                    l2 = l2->next;
<<<<<<< HEAD
                } else {
=======
                }
                else {
>>>>>>> 630b80c... add solution for merging two sorted lists
                    res->next = new ListNode(l1->val);
                    res = res->next;
                    l1 = l1->next;
                }
            }
            
            while(l1 != nullptr) {
                res->next = new ListNode(l1->val);
                res = res->next;
                l1 = l1->next;
            }
            
            while(l2 != nullptr) {
                res->next = new ListNode(l2->val);
                res = res->next;
                l2 = l2->next;
            }
            return pNode->next;
        }
    }
};

<<<<<<< HEAD
int main(int argc, const char* argv[]) {
	/** TODO **/
	Solution().mergeTwoLists();
=======
int main(int argc, const char** argv)
{
	/** TODO **/
	Solution solver;
	solver.mergeTwoLists();
>>>>>>> 630b80c... add solution for merging two sorted lists

	return 0;
}
