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
// 3. Longest Substring Without Repeating Characters
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

class Solution {
public:
	/*=========================================================================
	 * Description:  Given a string, find the length of the longest substring
	 *				 without repeating characters.
	 * Example: Input: "abcabcbb"
	 *	    Output: 3
	 *	    Explanation: The answer is "abc", with the length of 3
	 *	    
	 *	    Input: "bbbbb"
	 *	    Output: 1
	 *	    Explanation: The answer is "b", with the length of 1
	 *	    
	 *	    Input: "pwwkew"
	 *	    Output: 3
	 *	    Explanation: The answer is "wke", with the length of 3. Note
	 *	    that the answer must be a substring, "pwke" is a subsequence
	 *	    and not a substring.
	 *=========================================================================
	 */
	int lengthOfLongestSubstring(std::string s) {
		if (s.empty()) return 0;

		int maxLen = 0;
		int strLen = s.length();
		std::unordered_map<char, int> umRes;
		for (size_t i = 0; i < strLen; i++) {
			if (umRes.find(s[i]) != umRes.end()) {
				i = umRes[s[i]] - 1;
				umRes.clear();
			} else {
				umRes.insert({s[i], i+1});
				maxLen = max((int)umRes.size(), maxLen);
			}
		}

		return maxLen;
	}
};

int main (int argc, char *argv[]) {
	std::string s = "pwwkew";
	Solution solver;
	int len = solver.lengthOfLongestSubstring(s);
	std::cout << "string: " << s << std::endl;
	std::cout << "max length of substring: " << len << std::endl;

	return 0;
}

// ====== End Of File ====== //
