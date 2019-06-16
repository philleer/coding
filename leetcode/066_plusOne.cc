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
// or just correct it via Pull Request or create an issue.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*=============================================================
     * Description: Given a non-empty array of digits representing
     *              a non-negative integer, plus 1 to the integer.
     *              The digits are stored such that the most
     *              significant digit is at the head of the list,
     *              and each element in the array contain a single
     *              digit. You may assume the integer doesn't
     *              contain any leading zero, except the number 0.
     * Example:     Input: [1,2,3]  Output: [1,2,4]
     * Explanation: The array represents the integer 123.
     *              Input: [4,3,2,1]    Output: [4,3,2,2]
     * Explanation: The array represents the integer 4321.
     *=============================================================
     */
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> res(digits.size()+1);
        
        for (int i = digits.size()-1; i >= 0; i--) {
            res[i+1] = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
        }
        
        if (carry)
            res[0] = 1;
        else
            res.erase(res.begin());
        return res;        
    }

    vector<int> plusOneChanged(vector<int>& digits) {
        int temp = 0;
        int carry = 1;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            temp = (digits[i] + carry) / 10;
            digits[i] = (digits[i] + carry) % 10;;
            carry = temp;
        }
        
        if (carry)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

int main(int argc, char **argv) {
    int array[] = {5,4,3,2,9};
    vector<int> vectorTest;
    vectorTest.assign(array, array + sizeof(array)/sizeof(array[0]));

    printf("Before manipulation:\n");
    for (int i = 0; i < vectorTest.size(); i++) {
        printf("%d\t", vectorTest[i]);
    }
    printf("\n");

    Solution solver;
    vector<int> res = solver.plusOne(vectorTest);
    
    printf("After manipulation via plusOne:\n");
    for (int i = 0; i < res.size(); i++) {
        printf("%d\t", res[i]);
    }
    printf("\n");

    printf("Before manipulation:\n");
    for (int i = 0; i < vectorTest.size(); i++) {
        printf("%d\t", vectorTest[i]);
    }
    printf("\n");
    solver.plusOneChanged(vectorTest);
    printf("After manipulation via plusOneChanged:\n");
    for (int i = 0; i < vectorTest.size(); i++) {
        printf("%d\t", vectorTest[i]);
    }
    printf("\n");


    return 0;
}
