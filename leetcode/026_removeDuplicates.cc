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
// 26. Remove Duplicates from Sorted Array
#include <iostream>
#include <vector>

class Solution {
public:
	/*=========================================================================
	 * Description: Given a sorted array nums, remove the duplicates in-place
	 *	such that each element appear only once and return the new length.
	 *	Do not allocate extra space for another array, you must do this by
	 *	modifying the input array in-place with O(1) extra memory.
	 * Example:
	 *	Input: [1,1,2]	Output: 2
	 *	Explination: Your function should return length = 2, with the first
	 *	two elements of nums being 1 and 2 respectively. It doesn't matter
	 *	what you leave beyond the returned length.
	 *	
	 *	Input: [0,0,1,1,1,2,2,3,3,4]	Output: 5
	 *	Explination: Your function should return length = 5, with the first
	 *	five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
	 *	It doesn't matter what values are set beyond the returned length.
	 *
	 * Clarification:
	 *	Confused why the returned value is an integer but your answer is an array?
	 *  Note that the input array is passed in by reference, which means
	 *	modification to the input array will be known to the caller as well.
	 *	Internally you can think of this:
	 *		// nums is passed in by reference. (i.e., without making a copy)
	 *		int len = removeDuplicates(nums);
	 *		// any modification to nums would be known by the caller.
	 *		// using the length returned, it prints the first len elements.
	 *		for (int i = 0; i < len; i++) { print(nums[i]); }
	 *=========================================================================
	 */
	int removeDuplicates(std::vector<int>& nums) {
		int n = nums.size();
		if (n < 2)
			return n;
		
		int index = 0;
		for (int i = 0; i < n-1; ++i) {
			if (nums[i] == nums[i+1]) ++index;
			else nums[i-index] = nums[i];
		}
		nums[n-1-index] = nums[n-1];
		
		return (n-index);
	}
};

int main(int argc, char *argv[]) {
	std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};
	Solution solver;
	
	int result = solver.removeDuplicates(nums);
	std::cout << "array before modified: " << std::endl;
	for (auto &num : nums) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "array after modified:" << std::endl;
	for (int i = 0; i < result; ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

