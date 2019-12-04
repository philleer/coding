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
#include <string> // std::string::begin, std::string::end, std::string::erase
		  // std::stoi
#include <cctype>	// isspace
#include <algorithm>	// std::max, std::min
#include <sstream>	// std::stringstream

class Solution {
public:
	// 11. Container With Most Water
	/*=====================================================================
	 * Description: Given n non-negative integers a1, a2, ..., an , where
	 *	each represents a point at coordinate (i, ai). n vertical lines
	 *	are drawn such that the two endpoints of line i is at (i, ai)
	 *	and (i, 0). Find 2 lines, which together with x-axis forms a
	 *	container, such that the container contains the most water.
	 * Note: You may not slant the container and n is at least 2.
	 * 
	 * Example:
	 *	Input: [1,8,6,2,5,4,8,3,7] 	Output: 49
	 *=====================================================================
	 */
	int maxArea1(std::vector<int>& height) {
		if (height.size() < 2) return 0;
		
		int area = 0, max = 0;
		for (int i = 0; i < height.size()-1; ++i) {
			for (int j = i+1; j < height.size(); ++j) {
				max = std::max(std::min(height[i],
							height[j])*(j-i), max);
			}
		}
		
		return max;
	}

	int maxArea(std::vector<int>& height) {
		if (height.size() < 2) return 0;
		
		int result = 0;
		int i = 0, j = height.size()-1;
		while (i < j) {
			result = std::max(result, std::min(height[i],
							   height[j])*(j-i));
			height[i] < height[j] ? ++i : --j;
		}
		
		return result;
	}
};

void trimLeftTrailingSpaces(std::string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(),
			[](int ch) { return !isspace(ch);}
		));
}

void trimRightTrailingSpaces(std::string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
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
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(std::stoi(item));
	}
	return output;
}

int main(int argc, char *argv[]) {
	std::string line;
	while (getline(std::cin, line)) {
		std::vector<int> height = stringToIntegerVector(line);
		int ret = Solution().maxArea(height);
		std::string out = std::to_string(ret);
		std::cout << out << std::endl;
	}

	return 0;
}
