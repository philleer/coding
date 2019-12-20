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
#include <vector>       // std::vector
#include <cstddef>      // size_t

class Solution {
public:
	// 665. Non-decreasing Array
	/*=====================================================================
	 * Description: Given an array with n integers, your task is to check
	 *	if it could become non-decreasing by modifying at most 1 element.
	 *      We define array is non-decreasing if array[i] <= array[i + 1]
	 *      holds for every i(0 <= i < n).
	 *
	 * Example :
	 *	Input1: [4,2,3]		Output1: True
	 * 	Explanation: Modify 4 to 1 to get a non-decreasing array.
	 *
	 *      Input2: [4,2,1]		Output: False
	 *	Explanation: You can't get a non-decreasing array by modify at
	 *      most one element.
	 * Note : The n belongs to [1, 10,000].
	 *=====================================================================
	 */
	bool checkPossibility(std::vector<int>& nums) {
        	if (nums.empty()) return true;

		size_t num = 0;
		size_t size = nums.size();
		for (size_t i = 0; i < size-1; ++i) {
			if (nums[i] <= nums[i+1]) continue;
			// 第一次AC时的代码
			// ====================================================
			if (i > 0 && i < size-2) {
				if (nums[i+1] > nums[i+2] ||
				    (nums[i-1] > nums[i+1] &&
				     nums[i] > nums[i+2]))
				{
				    return false;
				} else {
				    ++num;
				}
			} else { ++num;	}
			// ====================================================

			// 稍微改进精简一下代码
			// ====================================================
			++num;
			if (i > 0 && i < size-2) {
				if (nums[i+1]>nums[i+2] ||
				    (nums[i-1]>nums[i+1] && nums[i]>nums[i+2]))
				{
				    return false;
				}
			}
			// ====================================================
		}
		return num <= 1 ? true : false;
	}

	// 别人的实现方式（略有改动）
	bool checkPossibility_rth(std::vector<int>& nums) {
		if (nums.empty()) return true;

		int count = 0;
		int size = nums.size();
		for (int i = 0; i < size-1; ++i) {
			if (nums[i] > nums[i+1]) {
				++count;
				if (i != 0 && i != size-2 &&
				    nums[i-1] > nums[i+1] &&
				    nums[i] > nums[i+2])
				{
					return false;
				}
		    	}
			if (count > 1) return false;
		}
		return true;
	}
};

int main(int argc, char const *argv[]) {
	std::vector<int> vec1 = {2, 3, 3, 2, 4};
	std::vector<int> vec2 = {-1, 4, 2, 3, 3};
	std::vector<int> vec3 = {3, 3, 2, 4};
	std::vector<int> vec3 = {3, 4, 2, 3};

	Solution solver;
	std::cout << "Is it possible to modify the array? "
		<< solver.checkPossibility(vec1) << std::endl;
	std::cout << "Is it possible to modify the array? "
		<< solver.checkPossibility(vec2) << std::endl;
	std::cout << "Is it possible to modify the array? "
		<< solver.checkPossibility(vec3) << std::endl;
	std::cout << "Is it possible to modify the array? "
		<< solver.checkPossibility(vec4) << std::endl;

	return 0;
}

