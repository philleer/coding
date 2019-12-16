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
#include <vector>
#include <algorithm>

class Solution {
public:
	// 198. House Robber
	/*=====================================================================
	 * Description: You are a professional robber planning to rob houses
	 *	along a street. Each house has a certain amount of money
	 *	stashed, the only constraint stopping you from robbing each of
	 *	them is that adjacent houses have security system connected and
	 *	it will automatically contact the police if two adjacent houses
	 *	were broken into on the same night.
	 *	Given a list of non-negative integers representing the amount
	 *	of money of each house, determine the maximum amount of money
	 *	you can rob tonight without alerting the police.
	 *
	 * Example:
	 *	Input: [1,2,3,1]	Output: 4
	 *	Explanation: Rob house 1 (money = 1) and then rob house 3
	 *	(money = 3). Total amount you can rob = 1 + 3 = 4.
	 *
	 *	Input: [2,7,9,3,1]	Output: 12
	 *	Explanation: Rob house 1 (money = 2), rob house 3 (money = 9)
	 *	and rob house 5 (money = 1). Total amount = 2 + 9 + 1 = 12.
	 *=====================================================================
	 */
	int rob(std::vector<int>& nums) {
		if (nums.empty()) return 0;
		int size = nums.size();
		if (size < 2) return nums[0];

		std::vector<int> val(size, 0);
		val[0] = std::max(nums[0], 0);
		val[1] = std::max(std::max(nums[0], nums[1]), 0);

		int res = val[1];
		for (int i = 2; i < size; ++i) {
			val[i] = std::max(nums[i]+val[i-2], val[i-1]);
			res = std::max(val[i], res);
		}

		return res;
	}
};

int main(int argc, char *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		int tmp;
		std::vector<int> nums;
		// 输入时保持用逗号隔开的格式
		while(std::getline(ss, tmp, ',')) nums.push_back(tmp);

		for (auto &num : nums) std::cout << num << " ";
		std::cout << std::endl;
		std::cout << "Money can be robbed: " <<
			Solution().rob(nums) << std::endl;
	}
	return 0;
}
