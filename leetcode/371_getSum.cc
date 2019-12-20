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

class Solution {
public:
	// 371. Sum of Two Integers
	/*=====================================================================
	 * Description: Calculate the sum of two integers a and b, but you are
	 *	not allowed to use the operator + and -.
	 *
	 * Example:
	 *	Input: a = 1, b = 2 	Output: 3
	 *
	 *	Input: a = -2, b = 3 	Output: 1
	 *=====================================================================
	 */
	int getSum(int a, int b) {
		return (a==0 ? b : getSum((unsigned int)(a&b)<<1, a^b));
	}
};

int stringToInteger(std::string input) {
	return std::stoi(input);
}

int main(int argc, const char* argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		int a = stringToInteger(line);
		std::getline(std::cin, line);
		int b = stringToInteger(line);
		
		std::cout << Solution().getSum(a, b) << std::endl;
	}
	return 0;
}

