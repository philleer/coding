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
#include <string>

using namespace std;

class Solution {
public:
	/*=============================================================
	 * Description: Given an unsorted array of integers, find the
	 * 				length of longest continuous increasing
	 * 				subsequence (subarray).
	 * Example 1: 	Input: [1,3,5,4,7]	Output: 3
	 *				Explanation: The longest continuous increasing
	 * 				subsequence is [1,3,5], its length is 3. Even
	 * 				though [1,3,5,7] is also an increasing 
	 * 				subsequence, it's not a continuous one where 5
	 *				and 7 are separated by 4.
	 * Example 2:	Input: [2,2,2,2,2]	Output: 1
	 *				Explanation: The lcis is [2], its length is 1. 
	 * Note:		Length of the array will not exceed 10,000.
	 *=============================================================
	 */
    int findLengthOfLCIS(vector<int>& nums) {
        // take special case into account
        if (nums.empty())
            return 0;

        int len = 1;
        int maxLen = 1;
        
        int i = 1;
        for (; i < nums.size(); i++) {
            if (nums[i] != '\0' && nums[i] > nums[i-1]) {
                len++;
            }
            else {
                if (len > maxLen) {
                    maxLen = len;
                }
                len = 1;
            }
        }
        // when increasing continues till the end and jump out
        // for-loop we need to set the maxLen to len of the last
        // substring if possible
        if (i == nums.size() && len > maxLen) {
            maxLen = len;
        }

        return maxLen;
    }

	/*=============================================================
	 * Description: Given an arbitrary string, displays the maximum
	 * 				consecutive increasingly ordered substring.
	 * Example 1: 	Input: Welcome	Output: Wel
	 *				Explanation: The longest continuous increasing
	 * 				subsequence is Wel. Even though Welo is also an
	 *				increasing subsequence, it's not continuous.
	 *=============================================================
	 */
    string findLongestCIS(string &str) {
		if (str.empty())
			return "";
		int startIndex = 0;
		int len = 1;

		pair<int, int> p(0, 1);
		int i = 1;
		for (; i < str.length(); i++) {
			if (str[i] != '\0' && str[i] > str[i-1]) {
				len++;
			}
			else {
				if (len > p.second)
				{
					p.first = startIndex;
					p.second = len;
				}
				startIndex = len;
				len = 1;
			}
		}
		if (i == str.length() && len > p.second) {
			p.first = startIndex;
			p.second = len;
		}

		return str.substr(p.first, p.second);
	}
};

int main(int argc, char **argv) {
	
	int arrayTest[5] = {1,3,5,4,7};
	vector<int> vectorTest;
	vectorTest.assign(arrayTest, arrayTest+5);
	
	// display the element in the arrayTest
	for (vector<int>::iterator it = vectorTest.begin();
		it != vectorTest.end(); it++)
		cout << *it << " ";
	cout << endl;
	
	Solution solver;
	// print the length of longest continuous increasing
	// subsequence
	cout << solver.findLengthOfLCIS(vectorTest) << endl;
	return 0;
}