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
#include <cmath>

#define	INFMIN -2147483647

using namespace std;

class Solution {
public:
	/*=============================================================
	 * Description: Given an integer array nums, find the 
	 * 				contiguous subarray(containing at least one
	 * 				number) which has the largest sum and return
	 *				its sum. 
	 * Example: 	Input: [-2,1,-3,4,-1,2,1,-5,4]	Output: 6
	 *				Explanation: [4,-1,2,1] has the largest sum = 6
	 * Follow up:	If you have figured out the O(n) solution, try
	 *				coding another solution using the divide and
	 *				conquer approach, which is more subtle.
	 *=============================================================
	 */

	/*
	 * Descriptiong: this function works as dynamic programming(DP)
	 * temp means the max subarray sum before nums[i], and it updates
	 * to max(temp+nums[i], nums[i]) each step
	 * maxSum log the maximun value in the process
	 * Time complexity : O(n)
	 * Space complexity : O(1)
	 */
	int maxSubArray1(vector<int> &nums) {
		// take special case into account
		if (nums.empty())
			return 0;

		int maxSum = nums[0] >= INFMIN ? nums[0] : 0;
		int temp = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (temp > 0)
				temp += nums[i];
			else
				temp = nums[i];

			if (temp > maxSum)
				maxSum = temp;
		}
		return maxSum;
	}

	/*
	 * Descriptiong: this function works recursively
	 * since the max subarray will exist in the left half part or in
	 * the right half part or from left to right part
	 * so we divide the problem to three similar subproblem and solve
	 * it respectively, that is divide-and-conquer
	 * Time complexity : T(n) = 2T(n/2) + n ==> O(n) = T(n) = O(nlogn)
	 */
	int maxSubArray2(vector<int> &nums) {
		return maxSubArrayRecursively(nums, 0, nums.size() - 1);
	}

    int maxSubArrayRecursively(vector<int> &nums, 
    	int leftIndex, int rightIndex) {
	    int maxSum = 0;
	    
	    if (leftIndex == rightIndex) {	// base case
	        return nums[leftIndex] >= INFMIN ? nums[leftIndex] : 0;
	    }
	    else {
	        int middleIndex = (leftIndex + rightIndex) / 2;
	        int maxLeftSum = maxSubArrayRecursively(nums, 
	        	leftIndex, middleIndex);
	        int maxRightSum = maxSubArrayRecursively(nums, 
	        	middleIndex + 1, rightIndex);
	        
	        int temp = 0;
	        int maxHalfSumLeft = INFMIN;
	        for (int i = middleIndex; i >= leftIndex; i--) {
	            temp += nums[i];
	            if (temp > maxHalfSumLeft)
	                maxHalfSumLeft = temp;
	        }

	        temp = 0;
	        int maxHalfSumRight = INFMIN;
	        for (int i = middleIndex + 1; i <= rightIndex; i++) {
	            temp += nums[i];
	            if (temp > maxHalfSumRight)
	                maxHalfSumRight = temp;
	        }
	        
	        maxSum = maxHalfSumLeft + maxHalfSumRight;
	        if (maxSum < maxLeftSum)
	            maxSum = maxLeftSum;
	        if (maxSum < maxRightSum)
	            maxSum = maxRightSum;
	    }

	    return maxSum;
};

int main(int argc, char **argv) {
	int arrayTest[2] = {-2,1};
	vector<int> nums;
	nums.assign(arrayTest, arrayTest + 2);

	Solution solver;
	cout << "Dynamic programming solution:"
		 << "\tMaximum addition of subarrays = "
		 << solver.maxSubArray1(nums)
		 << endl;
	cout << "Divide and conquer recursively:"
		 << "\tMaximum addition of subarrays = "
		 << solver.maxSubArray2(nums) 
		 << endl;		 

	return 0;
}