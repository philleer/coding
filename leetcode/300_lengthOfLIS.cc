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
#include <vector>

class Solution {
public:
	// 300. Longest Increasing Subsequence
	/*=====================================================================
	 * Description: Given an unsorted array of integers, find the length of
	 *	longest increasing subsequence.
	 *
	 * Example:
	 *	Input: [10,9,2,5,3,7,101,18] 	Output: 4
	 *	Explanation: The longest increasing subsequence is [2,3,7,101],
	 *	therefore the length is 4.
	 *
	 * Note:
	 *	There may be more than one LIS combination, it's only necessary
	 *	for you to return the length.
	 *	Your algorithm should run in O(n2) complexity.
	 *	Follow up: Could you improve it to O(n log n) time complexity?
	 *=====================================================================
	 */
	int lengthOfLIS(std::vector<int>& nums) {
		if (nums.size() == 0) return 0;

		int dp[nums.size()];
		for (int i = 0; i < nums.size(); i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j] && dp[i] <= dp[j])
					dp[i] = dp[j] + 1;
			}
		}

		int max = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (dp[i] > max) max = dp[i];
		}
		return max;
	}
};

int main(int argc, char *argv[]) {
	Solution solver;

	std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
	int len = solver.lengthOfLIS(nums);
	
	std::cout << "original array: " << std::endl;
	for (auto &num : nums) std::cout << num << " ";
	std::cout << std::endl;
	
	std::cout << "the length of longest increasing subsequence is: "
		<< len
		<< std::endl;

	return 0;
}

