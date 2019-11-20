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
// 4. Median of Two Sorted Arrays
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

class Solution {
public:
	/*=========================================================================
	 * Description: There are two sorted arrays nums1 and nums2 of size m and n
	 *	respectively. Find the median of the two sorted arrays. The overall
	 *	run time complexity should be O(log(m+n)). You may assume nums1 and
	 *	nums2 cannot be both empty.
	 * Example: Input: nums1 = [1, 3] nums2 = [2]
	 *	    Output: The median is 2.0
	 *
	 *	    Input: nums1 = [1, 2] nums2 = [3, 4]
	 *	    Output: The median is (2 + 3)/2 = 2.5
	 *=========================================================================
	 */
	double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
		int len1 = nums1.size(), len2 = nums2.size();

		// make sure that nums1 is the shorter array
		if (len1 > len2)
			return findMedianSortedArrays(nums2, nums1);

		if (nums1.empty())
			return (len2 & 1) ? (double)nums2[len2 / 2] :
				(nums2[len2 / 2] + nums2[len2 / 2 - 1]) / 2.0;

		double res = 0.0;
		int left = kth(&nums1[0], len1, &nums2[0], len2, (len1 + len2 + 1) / 2);
		if ((len1 + len2) & 1) {
			res = (double)left;
		} else {
			int right = kth(&nums1[0], len1, &nums2[0], len2, (len1 + len2 + 1) / 2 + 1);
			res = (double)(left + right) / 2.0;
		}

		return res;
	}

	int kth(int* m, int len1, int* n, int len2, int pos) {
		if (len1 == 0)	return n[pos -1];
		if (len2 == 0)	return m[pos - 1];
		if (pos == 1) 	return min(m[0], n[0]);
		
		int index1 = min(len1, pos / 2);
		int index2 = pos - index1;
		if (m[index1 - 1] < n[index2 - 1]) {
			return kth(m+index1, len1-index1, n, len2, pos-index1);
		} else {
			return kth(m, len1, n+index2, len2-index2, pos-index2);
		}
	}
};

int main (int argc, char *argv[]) {
	std::vector<int> nums1{1, 2};
	std::vector<int> nums2{3, 4};
	Solution solver;
	double result = solver.findMedianSortedArrays(nums1, nums2);
	
	std::cout << "nums1: ";
	for (int i = 0; i < nums1.size(); ++i) {
		std::cout << nums1[i] << " ";
	}
	std::cout << "nums2: ";
	for (int i = 0; i < nums2.size(); ++i) {
		std::cout << nums2[i] << " ";
	}
	std::cout << "median of the two arrays: " << result << std::endl;

	return 0;
}

