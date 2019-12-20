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
	// 35. Search Insert Position
	/*=====================================================================
	 * Description:  Given a sorted array and a target value, return the
	 *	index if the target is found. If not, return the index where it
	 *	would be if it were inserted in order.
	 *	You may assume no duplicates in the array.
	 *
	 * Example:
	 *	Input: [1,3,5,6], 5 Output: 2
	 *	Input: [1,3,5,6], 2 Output: 1
	 *	Input: [1,3,5,6], 7 Output: 4
	 *	Input: [1,3,5,6], 0 Output: 0
	 *=====================================================================
	 */
	int searchInsert(std::vector<int>& nums, int target) {
		int pos = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (target > nums[i]) ++pos;
			else break;
		}
		
		return pos;
	}
};

int main(int argc, const char *argv[]) {
	std::vector<int> nums1{1, 3, 5, 6};
	int target = 2;
	int result = Solution().searchInsert(nums1, target);

	for (auto &num : nums1) std::cout << num << " ";
	std::cout << std::endl;
	std::cout << target << " can be inserted in position: "
		<< result << std::endl;

	return 0;
}