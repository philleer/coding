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
#include <algorithm>

class Solution {
public:
	// 9. Palindrome Number
	/*=====================================================================
	 * Description:  Determine whether an integer is a palindrome. An
	 *	integer is a palindrome when it reads the same backward as
	 *	forward.
	 * Example:
	 *	Input: 121	Output: true
	 *    
	 *	Input: -121	Output: false
	 *	Explanation: From left to right, it reads -121. From right to
	 *	left, it becomes 121-. Therefore it is not a palindrome.
	 *    
	 *	Input: 10		Output: false
	 *	Explanation: Reads 01 from right to left. Therefore it is not a
	 *	palindrome.
	 *    
	 * Follow up: Coud you solve it without converting the integer to a
	 *	string?
	 *=====================================================================
	 */
	bool isPalindrome(int x) {
		if (x < 0) return false;
		else if (x >= 0 && x < 10) return true;
		else if (x <= 0x7fffffff) {
			long int res = 0;
			int val = x;
			
			while (val) {
				res = res * 10 + val % 10;
				val /= 10;
			}

			return ((int)res == x ? true : false);
		}
		
		return true;
	}
};

int main (int argc, const char *argv[]) {
	Solution solver;

	int x1 = 121;
	bool result1 = solver.isPalindrome(x1);
	std::cout << "x = " << x1
		<< (result1 ? "is " : "is not ")
		<< "palindrome"
		<< std::endl;

	int x2 = 10;
	bool result2 = solver.isPalindrome(x2);
	std::cout << "x = " << x2
		<< (result2 ? "is " : "is not ")
		<< "palindrome"
		<< std::endl;
	
	return 0;
}

