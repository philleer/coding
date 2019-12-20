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
#include <string>

class Solution {
public:
	// 22. Generate Parentheses
	/*=====================================================================
	 * Description: Given n pairs of parentheses, write a function to
	 *	generate all combinations of well-formed parentheses.
	 *
	 * Example:
	 *	Input: 3
	 *	Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]
	 *=====================================================================
	 */
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> result;
		std::string str;
		helper(result, str, 0, 0, n);
		return result;
	}
	
	// Note str is just a copy rather than reference here
	void helper(std::vector<std::string> &result, std::string str,
		int left, int right, int n) {
		if (str.length() == 2 * n) {
			result.push_back(str);
			return ;
		}
		
		if (left < n) helper(result, str+"(", left+1, right, n);
		if (right < left) helper(result, str+")", left, right+1, n);
	}
};

int main(int argc, const char *argv[]) {
	int n = 3;
	
	std::vector<std::string> result = Solution().generateParenthesis(n);
	for (int i = 0; i < result.size(); ++i) {
		std::cout << result[i] << std::endl;
	}

	return 0;
}

