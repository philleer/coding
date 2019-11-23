/******************************************************************************
 * The source is part of my coding practice, a lightweight C++ solution for
 * leetcode program practice.
 *
 * For all of my code, after check it online by submit, I also compile and run
 * it by my offline machine
 * ============================================================================
 * ////////////// Microsoft Visual Studio 2010 when I use windows /////////////
 * //////////////		   G++5.4.0 when I am on Linux           /////////////
 * ============================================================================
 *
 * If any question, feel free to send me an email << phillee2016@163.com >>
 * or just correct it via Pull Request or create an issue.
 ******************************************************************************
 */
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	// 344. Reverse String
	/*=========================================================================
	 * Description: Write a function that reverses a string. The input string
	 *	is given as an array of characters char[].
	 *	Do not allocate extra space for another array, you must do this by
	 *	modifying the input array in-place with O(1) extra memory.
	 *	You may assume all the characters consist of printable ascii characters.
	 *
	 * Example:
	 *	Input: ["h","e","l","l","o"] 	Output: ["o","l","l","e","h"]
	 *
	 *	Input: ["H","a","n","n","a","h"] 	Output: ["h","a","n","n","a","H"]
	 *=========================================================================
	 */
	void reverseString(std::vector<char> &s) {
		if (s.empty()) return;
		for (int i = 0; i <= (s.size() - 1) / 2; i++) {
			std::swap(s[i], s[s.size() - i - 1]);
		}
	}
};

int main(int argc, char *argv[]) {
	Solution solver;

	std::vector<char> str{'h', 'e', 'l', 'l', 'o'};
	solver.reverseString(str);
	std::cout << "original string: " << std::endl;
	for (auto &c : str) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	std::cout << "the reversed string: " << std::endl;
	for (auto &c : str) {
		std::cout << c << " ";
	}
	std::cout << std::endl;

	return 0;
}
