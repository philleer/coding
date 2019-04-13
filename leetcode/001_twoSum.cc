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
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/*=============================================================
	 * Description: Given an array of integers, return indices of 
	 * 				the two numbers such that they add up to a 
	 * 				specific target. You may assume that each input
	 *				would have exactly one solution, and you may 
	 *				not use the same element twice.			
	 * Example: Given nums = [2, 7, 11, 15], target = 9, since 
	 *			nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
	 *=============================================================
	 */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> p;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int tem = target - nums[i];
            if (p.count(tem))
            {
                
                res.push_back(p[tem]);
                res.push_back(i);
                break;
            }
            p[nums[i]] = i;
        }
        
        return res;
    }
};

int main (int argc, char **argv) {
	int nums[4] = {2, 7, 11, 15};
	vector<int> vectorTest(4);
	copy(nums, nums+4, vectorTest.begin());

	for (int i = 0; i < vectorTest.size(); i++)
		cout << vectorTest[i] << " ";
	cout << endl;

	Solution solver;
	vector<int> temp = solver.twoSum(vectorTest, 9);
	for (int j = 0; j < temp.size(); j++)
		cout << temp[j] << " ";
	cout << endl;

	return 0;
}
