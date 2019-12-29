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
	// 31. Next Permutation
	/*=====================================================================
	 * Description: Implement next permutation, which rearranges numbers
	 *	into the lexicographically next greater permutation of numbers.
	 *	If such arrangement is not possible, it must rearrange it as
	 *	the lowest possible order (ie, sorted in ascending order).
	 *	The replacement must be in-place and use only constant extra
	 *	memory.
	 *	Here are some examples. Inputs are in the left-hand column and
	 *	its corresponding outputs are in the right-hand column.
	 *
	 * Example:
	 *	Input: 1,2,3	Output: 1,2,3
	 *	Input: 3,2,1 	Output: 1,2,3
	 *	Input: 1,1,5	Output: 1,5,1
	 *=====================================================================
	 */
	void nextPermutation(std::vector<int>& nums) {
		if (nums.empty()) return ;
		if (1==nums.size()) return ;

		if (check(nums)) {
			std::reverse(nums.begin(), nums.end());
			return ;
		}

		for (int i = nums.size()-1; i >= 1; --i) {
			if (nums[i] > nums[i-1]) {
				for (int j = nums.size()-1; j >= i; --j) {
					if (nums[j] > nums[i-1]) {
						std::swap(nums[j], nums[i-1]);
						std::sort(nums.begin()+i,
							  nums.end());
						return ;
					}
				}
			}
		}
	}
    
private:
	bool check(std::vector<int> &nums) {
		int cnt = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] <= nums[i-1]) {
				++cnt;
				if (cnt >= nums.size()-1)
					return true;
			}
		}
		return false;
	}
};

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::string str;
		std::vector<int> nums;
		while (std::getline(ss, str, ' ')) {
			nums.push_back(std::atoi(str));
		}
		
		Solution().nextPermutation(nums);

		std::cout << "After permutation: " << std::endl;
		for (auto & num : nums) std::cout << num << " ";
		std::cout << std::endl;
	}

	return 0;
}

