/******************************************************************************
 * The source is part of my coding practice, a lightweight C++ solution for
 * leetcode program practice.
 *
 * For all of my code, after check it online by submit, I also compile and run
 * it by my offline machine
 * ============================================================================
 * ////////////// Microsoft Visual Studio 2010 when I use windows /////////////
 * //////////////	   G++5.4.0 when I am on Linux		  /////////////
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
	// 88. Merge Sorted Array
	/* ========================================================================
	 * Description: Given two sorted integer arrays nums1 and nums2, merge nums2
	 *	into nums1 as one sorted array.
	 * Note:
	 *	The number of elements initialized in nums1 and nums2 are m and n
	 *	respectively.
	 *	You may assume that nums1 has enough space (size >= m + n) to hold
	 *	additional elements from nums2.
	 * Example:
	 * 	Input: nums1=[1,2,3,0,0,0], m=3, nums2=[2,5,6], n=3
	 * 	Output: [1,2,2,3,5,6]
	 * ========================================================================
	 */
	void merge1(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		if (n <= 0) return ;
		if (m <= 0) {
			for (int i = 0; i < n; ++i) {
				nums1[i] = nums2[i];
			}
			return ;
		}
		
		int p1 = 0;
		int p2 = 0;
		while (p1 < m+n && p2 < n) {
			if (nums2[p2] <= nums1[p1]) {
				for (int i = m+p2-1; i >= p1; --i) {
					nums1[i+1] = nums1[i];
				}
				nums1[p1] = nums2[p2];
				++p2;
			}
			++p1;
			if (p1 >= m+p2 && p2 < n) {
				nums1[p1] = nums2[p2];
			}
		}
	}

	void merge2(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		if (n <= 0) return ;
		if (m <= 0) {
			for (int i = 0; i < n; ++i) {
				nums1[i] = nums2[i];
			}
			return ;
		}
		
		int p1 = m-1;
		int p2 = n-1;
		for (int i = m+n-1; i >= 0; --i) {
			if (p1 >= 0 && p2 >= 0) {
				nums1[i] = (nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--]);
			} else {
				nums1[i] = (p2>=0 ? nums2[p2--] : nums1[p1--]);
			}
		}
	}
};

int main(int argc, char *argv[]) {
	std::vector<int> nums1{1, 2, 3, 0, 0, 0};
	std::vector<int> nums2{2, 5, 6};
	int m = 3;
	int n = 3;
	Solution solver;

	std::cout << "Original vector: " << std::endl;
	for (int i = 0; i < m; ++i) {
		std::cout << nums1[i] << " ";
	}
	std::cout << std::endl;
	for (int j = 0; j < n; ++j) {
		std::cout << nums2[j] << " ";
	}
	std::cout << std::endl;
	solver.merge2(nums1, m, nums2, n);

	std::cout << "After merging: " << std::endl;
	for (int i = 0; i < m+n; ++i) {
		std::cout << nums1[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
