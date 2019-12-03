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
#include <iterator>

class Solution {
public:
	// 17. Letter Combinations of a Phone Number
	/*=====================================================================
	 * Description: Given a string containing digits from 2-9 inclusive,
	 *	return all possible letter combinations that the number could
	 *	represent.
	 *	A mapping of digit to letters (just like on the telephone
	 *	buttons) is given below. Note that 1 doesn't map to any letters.
	 *
	 * Example:
	 *	Input: "23"
	 *	Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
	 *
	 * Note:
	 *	Although the above answer is in lexicographical order, your
	 *	answer could be in any order you want.
	 *=====================================================================
	 */
	std::vector<std::string> letterCombinations(std::string digits) {
		std::vector<std::string> res;
		if (digits.empty()) return res;

		std::unordered_map<int, std::string> um{{2, "abc"}, {3, "def"},
							{4, "ghi"}, {5, "jkl"},
							{6, "mno"}, {7, "pqrs"},
							{8, "tuv"}, {9, "wxyz"}};

		int len = digits.length();
		std::vector<std::string> strs;
		for (int i = 0; i < len; ++i) {
			int tmp = digits[i]-'0';
			if (tmp >= 2 && tmp <= 9) strs.push_back(um[tmp]);
		}

		backtrack(strs, res, "", 0);
		return res;
	}
	
	void backtrack(
		std::vector<std::string> &strs,
		std::vector<std::string> &res,
		std::string solution,
		int level)
	{
		if (level >= strs.size()) {
			res.push_back(solution);
			return ;
		}

		for (int i = 0; i < strs[level].length(); ++i) {
			backtrack(strs, res, solution+strs[level][i], level+1);
		}
	}
};

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::string digits = line;
		std::cout << "given digits string: " << digits << std::endl;
		std::vector<std::string> res = Solution().letterCombinations(digits);
		std::cout << "letter combination result:" << std::endl;
		for (std::vector<std::string>::iterator it = res.begin();
			it != res.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	
	return 0;
}
