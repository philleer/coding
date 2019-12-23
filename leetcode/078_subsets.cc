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
#include <algorithm>

class Solution {
public:
	// 78. Subsets
	/*=====================================================================
	 * Description: Given a set of distinct integers, nums, return all
	 *	possible subsets (the power set).
	 *
	 * Example:
	 * 	Input: nums = [1,2,3]
	 *	Output: [[3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], []]
	 *=====================================================================
	 */
	std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
		std::vector<std::vector<int>> res;
		if (nums.empty()) return res;

		std::vector<int> nums_tmp = nums;
		std::reverse(nums_tmp.begin(), nums_tmp.end());
		std::vector<int> result;
		backtrack(nums_tmp, res, result, 0);

		return res;
	}

private:
	void backtrack(std::vector<int> &nums,
		       std::vector<std::vector<int>> &res,
		       std::vector<int> result,
		       int index)
	{
		if (index >= nums.size()) {
			res.push_back(result);
			return ;
		}

		backtrack(nums, res, result, index+1);
		result.push_back(nums[index]);
		backtrack(nums, res, result, index+1);
	}
};

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::vector<int> nums;
		char ch;
		while (std::getline(ss, ch, ',')) {
			nums.push_back(std::atoi(ch));
		}
		std::cout << "The input nums is:\n[ " << std::endl;
		for (auto &num : nums) std::cout << num << " ";
		std::cout << " ]" << std::endl;
		
		std::vector<std::vector<int>> res = Solution().subsets(nums);
		std::cout << "The subsets are:\n[" << std::endl;
		for (int i = 0; i < res.size(); ++i) {
			std::cout << "  [ ";
			for (int j = 0; j < res[i].size(); ++j) {
				std::cout << res[i][j] << " "
			}
			std::cout << " ]\n";
		}
		std::cout << "]" << std::endl;
	}

	return 0;
}

