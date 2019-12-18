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
// 8. String to Integer (atoi)
#include <iostream>
#include <string>

#define INT_MAX1 0x7fffffff
#define INT_MIN1 ((int)0x80000000)

#define INT_MAX 2147483647
#define INT_MIN (-2147483648)

class Solution {
public:
	/*=========================================================================
	 * Description:  Implement atoi which converts a string to an integer. The
	 *	function first discards as many whitespace characters as necessary
	 *	until the first non-whitespace character is found. Then starting
	 *	from this character, takes an optional initial plus or minus sign
	 *	followed by as many numerical digits as possible, and interprets
	 *	them as a numerical value.
	 *	The string can contain additional characters after those that form
	 *	the integral number, which are ignored and have no effect on the
	 *	behavior of this function. If the first sequence of non-whitespace
	 *	characters in str is not a valid integral number, or if no such
	 *	sequence exists because either str is empty or it contains only
	 *	whitespace characters, no conversion is performed.
	 *	If no valid conversion could be performed, 0 is returned.
	 * Note: Only the space character ' ' is considered as whitespace. Assume
	 *	we are dealing with an environment which could only store integers
	 *	within the 32-bit signed integer range: [−2^31, 2^31 − 1]. If the
	 *	numerical value is out of the range of representable values,
	 *	INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
	 * Example:
	 *	Input: "42"		Output: 42
	 *
	 *	Input: "   -42"		Output: -42
	 *	Explanation: The first non-whitespace character is '-', which is the
	 *	    minus sign.Then take as many numerical digits as possible, it's 42.
	 *
	 *	Input: "4193 with words"	Output: 4193
	 *	Explanation: Conversion stops at digit '3' as the next character is not
	 *	    a numerical digit.
	 *	
	 *	Input: "words and 987"	Output: 0
	 *	Explanation: The first non-whitespace character is 'w', which is not a
	 *	    numerical digit or a +/- sign. Therefore no valid conversion could
	 *	    be performed.
	 *
	 *	Input: "-91283472332"	Output: -2147483648
	 *	Explanation: The number "-91283472332" is out of the range of a 32-bit
	 *	    signed integer. Thefore INT_MIN (−231) is returned.
	 *=========================================================================
	 */
	int myAtoi1(std::string str) {
		if (str.empty()) return 0;
		
		int i = 0;
		int sign = 1;
		long long res = 0;
		
		while (str[i] == ' ') ++i;
		
		if ((str[i] == '+') && ((str[i+1] == str[i]) || (str[i+1] == '-')))
			return 0;
		else if ((str[i] == '-') && ((str[i+1] == str[i]) || (str[i+1] == '+')))
			return 0;
		
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-') {
			while (str[i] != '\0') {
				if (str[i] == '-') sign = -1;
				
				if (res > INT_MAX1) break;
				
				if (str[i] >= '0' && str[i] <= '9') {
					res = res * 10 + (str[i] - '0');
				}
				++i;
				if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
					break;
				if (sign == -1 && (str[i] < '0' || str[i] > '9'))
					break; 
			}
		}
		
		if (sign == -1)
			res = -res;
		
		return (res > INT_MAX1 ? INT_MAX1 : (res < INT_MIN1 ? INT_MIN1 : (int)res));
	}

	int myAtoi(std::string str) {
		if (str.empty()) return 0;
		
		int i = 0;
		int sign = 1;
		long long res = 0;
		
		while (str[i] == ' ') ++i;
		
		if ((str[i] == '+') && ((str[i+1] == str[i]) || (str[i+1] == '-')))
			return 0;
		else if ((str[i] == '-') && ((str[i+1] == str[i]) || (str[i+1] == '+')))
			return 0;
		
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-') {
			while (str[i] != '\0') {
				if (str[i] == '-')
					sign = -1;
				
				if (res > INT_MAX) break;
				if (str[i] >= '0' && str[i] <= '9') {
					res = res * 10 + (str[i] - '0');
				}

				++i;
				if (str[i] != '\0' && (str[i] < '0' || str[i] > '9')) break;
				if (sign == -1 && (str[i] < '0' || str[i] > '9')) break;
			}
		}
		
		if (sign == -1)
			res = -res;

		return (res > INT_MAX ? INT_MAX : (res < INT_MIN ? INT_MIN : (int)res));
	}
};

int main (int argc, char *argv[]) {
	Solution solver;

	std::string s1 = "4193 with words";
	int result1 = solver.myAtoi(s1);
	std::cout << "string: " << s1 << std::endl;
	std::cout << "the corresponding int: " << result1 << std::endl;

	std::string s2 = "-91283472332";
	int result2 = solver.myAtoi(s2);
	std::cout << "string: " << s2 << std::endl;
	std::cout << "the corresponding int: " << result2 << std::endl;
	
	return 0;
}

