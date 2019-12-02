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
#include <sstream>	// std::stringstream
#include <string>	// std::string::begin, std::string::end, std::string::erase
			// std::stoi
#include <algorithm>	// std::max, std::min
#include <vector>

class Solution {
public:
	// 14. Longest Common Prefix
	/*=========================================================================
	 * Description: Write a function to find the longest common prefix string
	 *	amongst an array of strings. If there is no common prefix, return "".
	 * Note: All given inputs are in lowercase letters a-z.
	 * 
	 * Example:
	 *	Input: ["flower","flow","flight"] 	Output: "fl"
	 *
	 *	Input: ["dog","racecar","car"] 		Output: ""
	 *	Explanation: There is no common prefix among the input strings.
	 *=========================================================================
	 */
	std::string longestCommonPrefix1(std::vector<std::string>& strs) {
		if (strs.empty()) return "";
		int len = 65536, index = 0;
		for (int i = 0; i < strs.size(); ++i) {
			if (len > strs[i].length()) {
				len = strs[i].length();
				index = i;
			}
		}
		
		int minlen = 65536;
		for (int i = 0; i < strs.size(); ++i) {
			if (i != index) {
				int tmp = 0, maxlen = 0;
				for (int j = 0; j < strs[index].length(); ++j) {
					if (j < strs[i].size() && strs[i][j] == strs[index][j]) {
						maxlen = std::max(++tmp, maxlen);
					} else {
						break;
					}
				}
				minlen = std::min(maxlen, minlen);
			}
		}
		
		return strs[index].substr(0, minlen);
	}

	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if (strs.empty()) return "";
		
		std::sort(strs.begin(), strs.end());
		std::string common = strs[0];
		int len = std::min(common.length(), strs[strs.size()-1].length());
		for (int j = 0; j < len; ++j) {
			if (strs[strs.size()-1][j] != common[j]) {
				common[j] = '\0';
				break;
			}
		}
		
		return common;
	}
};

int main(int argc, char *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::string str;
		std::vector<std::string> strs;
		while (std::getline(ss, str, ' ')) {
			strs.push_back(str);
		}

		std::string res = Solution().longestCommonPrefix(strs);
		std::cout << res << std::endl;
	}

	return 0;
}
