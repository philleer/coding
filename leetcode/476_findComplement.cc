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
#include <unordered_map>
#include <algorithm>

class Solution {
public:
	// 476. Number Complement
	/*=====================================================================
	 * Description: Given a positive integer, output its complement number.
	 *	The complement strategy is to flip the bits of its binary
	 *	representation.
	 * Note:
	 *	The given integer is guaranteed to fit within the range of a
	 *	32-bit signed integer. You could assume no leading 0 in the
	 *	integer’s binary representation.
	 * Example:
	 *	Input: 5 	Output: 2
	 *	Explanation: The binary representation of 5 is 101 (no leading
	 *	zeros),	and its complement is 010. So you need to output 2.
	 *
	 *	Input: 1 	Output: 0
	 *	Explanation: The binary representation of 1 is 1 (no leading
	 *	zeros), and its complement is 0. So you need to output 0.
	 *=====================================================================
	 */
	int findComplement(int num) {
		int numOfBits = (int)log2(num)+1;
		int tmp = 1;
		for (int k = 0; k < j; k++) {
			num ^= tmp;
			tmp <<= 1;
		}

		return num;
	}
};

int main(int argc, char const *argv[]) {
	int num = 5;
	int ret = Solution().findComplement(num);
	std::cout << "original number: " << num << std::endl;
	std::cout << "the complement number: " << ret << std::endl;

	return 0;
}

