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
#include <priority_queue>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cctype>

#ifndef INT_MAX
#define INT_MAX 4294967295
#endif

class Solution {
public:
	// 215. Kth Largest Element in an Array
	/*=====================================================================
	 * Description: Find the kth largest element in an unsorted array. Note
	 *	that it is the kth largest element in the sorted order, not the
	 *	kth distinct element.
	 *
	 * Example:
	 *	Input: [3,2,1,5,6,4] and k = 2
	 *	Output: 5
	 *
	 *	Input: [3,2,3,1,2,4,5,5,6] and k = 4
	 *	Output: 4
	 * Note:
	 *	You may assume k is always valid, 1 ≤ k ≤ array's length.
	 *=====================================================================
	 */
	// 第一种方法使用一个额外的双边队列保存最大的前k个元素
	int findKthLargest(std::vector<int>& nums, int k) {
		if (nums.empty() || nums.size() < k) return INT_MAX;

		std::deque<int> dq;
		for (int i = 0; i < nums.size(); ++i) {
			if (dq.size() < k) {
				dq.push_back(nums[i]);
			} else {
				for (std::deque<int>::iterator it = dq.begin();
				     it != dq.end()-1; it++)
				{
					if (*it < dq.back()) {
						std::swap(*it, dq.back());
					}
				}
				if (nums[i] > dq.back()) {
					dq.pop_back();
					dq.push_front(nums[i]);
				}
			}
		}

		int min = 65535;
		while (!dq.empty()) {
			int tmp = dq.back();
			dq.pop_back();
			if (tmp < min) min = tmp;
		}

		return min;
	}

	// 第二种方法，使用小顶堆，优先队列实现前k个最大的元素的保存
	int findKthLargestImp(std::vector<int>& nums, int k) {
		if (nums.empty() || nums.size() < k) return INT_MAX;

		std::priority_queue<int, std::vector<int>, greater<int>> pq;
		for (auto &num : nums) {
			if (pq.size() < k) {
				pq.push(num);
			} else {
				if (num > pq.top()) {
					pq.pop();
					pq.push(num);
				}
			}
		}


		return pq.top();
	}

	// 第三种方法，使用快排中的分割算法，一次缩小搜索范围找出第k大的元素
	int findKthLargestQS(std::vector<int>& nums, int k) {
		if (nums.empty()) return 0;
		int size = nums.size();
		if (size < k) return 0;

		int low = 0;
		int high = nums.size()-1;
		while (low < high) {
			int p = partition(nums, low, high);
			if (p == k-1) return nums[p];
			if (p < k-1) low = p+1;
			else high = p-1;
		}

		return nums[k-1];
	}

private:
	int partition(std::vector<int>& nums, int low, int high) {
		int pivot = nums[high];
		int left = low;
		int right = high-1;
		while (left < right) {
			while (left <= right && nums[left] <= pivot) ++left;
			while (left <= right && nums[right] > pivot) --right;
			if (left < right) std::swap(nums[left], nums[right]);
		}

		while (left < high && nums[left] < pivot) ++left;
		if (pivot < nums[left]) {
			nums[high] = nums[left];
			nums[left] = pivot;
			return left;
		}
		
		return high;
	}
};

void trimLeftTrailingSpaces(std::string &input) {
	input.erase(input.begin(), std::find_if(input.begin(), input.end(),
    		[](int ch) { return !isspace(ch); }
    	));
}

void trimRightTrailingSpaces(std::string &input) {
	input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

std::vector<int> stringToIntegerVector(std::string input) {
	std::vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	std::stringstream ss;
	ss.str(input);
	std::string item;
	while (std::getline(ss, item, ',')) {
		output.push_back(std::stoi(item));
	}
	return output;
}

int stringToInteger(std::string input) {
	return std::stoi(input);
}

int main(int argc, char const * argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::vector<int> nums = stringToIntegerVector(line);
		std::getline(std::cin, line);
		int k = stringToInteger(line);

		int ret = Solution().findKthLargest(nums, k);
		std::string out = to_string(ret);
		cout << out << endl;
	}

	return 0;
}

