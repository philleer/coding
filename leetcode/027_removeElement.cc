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
// 27. Remove Element
#include <iostream>
#include <vector>

class Solution {
public:
	/*=========================================================================
	 * Description: Given an array nums and a value val, remove all instances
	 * 	of that value in-place and return the new length. Do not allocate
	 * 	extra space for another array, you must do this by modifying the
	 * 	input array in-place with O(1) extra memory. The order of elements
	 * 	can be changed. Doesn't matter what you leave beyond the new length.
	 * Example:
	 *	Input: [3,2,2,3], val = 3	Output: 3
	 *	Explination: Your function should return length = 2, with the first
	 *	two elements of nums being 2. It doesn't matter	what you leave
	 *	beyond the returned length.
	 *	
	 *	Input: [0,1,2,2,3,0,4,2], val = 2	Output: 2
	 *	Explination: Your function should return length = 5, with the first
	 *	five elements of nums containing 0, 1, 3, 0, and 4. Note that the
	 *	order of those five elements can be arbitrary. It doesn't matter
	 *	what values are set beyond the returned length.
	 *
	 * Clarification:
	 *  Confused why the returned value is an integer but your answer is an array?
	 *  Note that the input array is passed in by reference, which means
	 *	modification to the input array will be known to the caller as well.
	 *	Internally you can think of this:
	 *          // nums is passed in by reference. (without making a copy)
	 *	    int len = removeDuplicates(nums);
	 *	    // any modification to nums would be known by the caller.
	 *	    // using the length returned, it prints the first len elements.
	 *	    for (int i = 0; i < len; i++) { print(nums[i]); }
	 *=========================================================================
	 */
	int removeElement(std::vector<int>& nums, int val) {
		if (nums.empty()) return 0;

		int n = nums.size();
		
		int del = 0;
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (*it == val) {
				it = nums.erase(it);
				++del;
				it--;
			}
		}
		
		return (n-del);
	}
};

int main(int argc, char *argv[]) {
	std::vector<int> nums{0,1,2,2,3,0,4,2};
	int val = 2;
	Solution solver;
	
	int result = solver.removeElement(nums, val);
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

