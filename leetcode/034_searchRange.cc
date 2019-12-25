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
#include <vector>
#include <string>
#include <cctype>

class Solution {
public:
	// 34. Find First and Last Position of Element in Sorted Array
	/*=====================================================================
	 * Description: Given an array of integers nums sorted in ascending
	 *	order, find the starting and ending position of a given target
	 *	value. Your algorithm's runtime complexity must be in the order
	 *	of O(log n).
	 *	If the target is not found in the array, return [-1, -1].
	 *
	 * Example:
	 * 	Input: nums = [5,7,7,8,8,10], target = 8 	Output: [3,4]
	 * 	Input: nums = [5,7,7,8,8,10], target = 6 	Output: [-1,-1]
	 *=====================================================================
	 */
	std::vector<int> searchRange(std::vector<int>& nums, int target) {
		std::vector<int> res(2, -1);
		if (nums.empty()) return res;

		int size = nums.size()-1;
		int low = 0, high = size;
		int mid = (low+high)/2;
		while (low < high) {
			if (nums[mid] >= target) high = mid-1;
			else low = mid+1;
			if (low <= high) mid = (low+high)/2;
		}
		if (nums[mid] < target && mid < size && nums[mid+1] == target) {
			res[0] = low+1;
		} else if (nums[mid] == target) {
			res[0] = low;
		}

		low = 0, high = size, mid = (low+high)/2;
		while (low < high) {
			if (nums[mid] <= target) low = mid+1;
			else high = mid-1;
			mid = (low+high)/2;
		}
		if (nums[mid] > target && mid >= 1 && nums[mid-1] == target) {
			res[1] = high-1;
		} else if (nums[mid] == target) {
			res[1] = high;
		}

		return res;
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

std::string integerVectorToString(std::vector<int> list, int length = -1) {
	if (length == -1) length = list.size();
	if (length == 0) return "[]";

	std::string result;
	for(int index = 0; index < length; ++index) {
		int number = list[index];
		result += std::to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(int argc, char const*argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::vector<int> nums = stringToIntegerVector(line);
		std::getline(std::cin, line);
		int target = stringToInteger(line);

		std::vector<int> ret = Solution().searchRange(nums, target);
		std::string out = integerVectorToString(ret);
		std::cout << out << std::endl;
	}

	return 0;
}

