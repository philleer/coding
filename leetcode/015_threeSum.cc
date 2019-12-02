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
#include <string>	// std::string::begin, std::string::end, std::string::erase
					// std::stoi
#include <cctype>	// isspace
#include <algorithm>	// std::max, std::min, std::sort
#include <sstream>	// std::stringstream

class Solution {
public:
	// 15. 3Sum
	/*=========================================================================
	 * Description: Given an array nums of n integers, are there elements a, b,
	 *	c in nums such that a+b+c = 0 ? Find all unique triplets in the array
	 *	which gives the sum of zero.
	 * Note: The solution set must not contain duplicate triplets.
	 * 
	 * Example:
	 *	Given array nums = [-1, 0, 1, 2, -1, -4]
	 *	A solution set is: [[-1, 0, 1], [-1, -1, 2]]
	 *=========================================================================
	 */
	std::vector<std::vector<int>> threeSum1(std::vector<int>& nums) {
		std::vector<std::vector<int>> res;
		int size = nums.size();
		if (size < 3) return res;
		
		std::sort(nums.begin(), nums.end());
		if (nums[0] > 0 || nums[size-1] < 0) return res;
		if (0 == nums[0] && 0 == nums[size-1]) {
			std::vector<int> tmp{0,0,0};
			res.push_back(tmp);
			return res;
		}
		
		for (int i = 0; i < size-2; ++i) {
			if (i>0 && nums[i] == nums[i-1]) continue;
			
			int sum = -nums[i];
			int low = i+1;
			int high = size-1;
			while (low < high) {
				if (nums[low]+nums[high] < sum) {
					++low;
					while (low < size-1 && nums[low-1]==nums[low]) ++low;
				} else if (nums[low]+nums[high] > sum) {
					--high;
					while (nums[high+1]==nums[high]) --high;
				} else {
					std::vector<int> tmp{nums[i], nums[low], nums[high]};
					res.push_back(tmp);
					--high;
					while (nums[high+1]==nums[high]) --high;
				}
			}
		}
		
		return res;
	}

	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> res;
		int size = nums.size();
		if (size < 3) return res;
		
		std::sort(nums.begin(), nums.end());
		if (nums[0] > 0 || nums[size-1] < 0) return res;
		for (int i = 0; i < size-2; ++i) {
			if (i>0 && nums[i] == nums[i-1]) continue;
			
			int low = i+1;
			int high = size-1;
			while (low < high) {
				int sum = nums[i]+nums[low]+nums[high];
				if (sum < 0) {
					++low;
					while (high > low && nums[low-1]==nums[low]) ++low;
				} else {
					if (0 == sum) {
						std::vector<int> tmp{nums[i], nums[low], nums[high]};
						res.push_back(tmp);
					}
					--high;
					while (high > low && nums[high+1]==nums[high]) --high;
				}
			}
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	std::string line;
	// -1, 0, 1, 2, -1, -4
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		int tmp;
		std::vector<int> nums;
		while (std::getline(ss, tmp, ',')) {
			nums.push_back(tmp);
		}

		std::vector<std::vector<int>> res = Solution().threeSum(nums);

		for (int i = 0; i < res.size(); ++i) {
			for (int j = 0; j < res[i].size(); ++j) {
				std::cout << res << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}
