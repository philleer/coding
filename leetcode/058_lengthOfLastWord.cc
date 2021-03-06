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

class Solution {
public:
	// 58. Length of Last Word
	/*=====================================================================
	 * Description: Given a string s consists of upper/lower-case alphabets
	 * 	and empty space characters ' ', return the length of last word
	 * 	in the string.
	 *	If the last word does not exist, return 0.
	 *
	 * Note:
	 *	A word is defined as a character sequence consists of non-space
	 *	characters only.
	 *
	 * Example:
	 * 	Input: "Hello World"	Output: 5
	 *=====================================================================
	 */
	int lengthOfLastWord(std::string s) {
		if (s.empty()) return 0;

		int index = 0, res = 0;
		for (int i = s.length()-1; i >= 0; --i) {
			if (i == s.length()-1 && s[i] == ' ') {
				while (i>0 && s[--i] == ' ');
				if (i>0) ++i;
			} else {
				index = i;
				break;
			}
		}

		for (int i = index; i >= 0; --i) {
			if (s[i] != ' ') ++res;
			else break;
		}

		return res;
	}
};

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::cout << "The input string is:\n" << line << std::endl;
		std::cout << "The length of the last word is:\n"
			<< Solution().lengthOfLastWord(line) << std::endl;
	}

	return 0;
}

