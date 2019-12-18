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
	// 13. Roman to Integer
	/*=====================================================================
	 * Description: Roman numerals are represented by seven different
	 *	symbols: I, V, X, L, C, D and M, which means value 1, 5, 10, 50,
	 * 	100, 500, 1000 respectively.
	 * Note:
	 *	2 is written as II in Roman numeral, two one's added together.
	 *	12 is written as, XII, which is simply X + II.
	 *	27 is written as XXVII, which is XX + V + II.
	 *	Roman numerals are usually written largest to smallest from
	 *	left to right. However, the numeral for 4 is not IIII. Instead,
	 *	it is written as IV. Because the one is before the five we
	 *	subtract it making four. The same principle applies to the
	 *	number 9, which is written as IX.
	 *	There are six instances where subtraction is used:
	 *		I can be placed before V and X to make 4 and 9.
	 *		X can be placed before L and C to make 40 and 90.
	 *		C can be placed before D and M to make 400 and 900.
	 *	Given a roman numeral, convert it to an integer. Input is
	 *	guaranteed to be within the range from 1 to 3999.
	 * Example:
	 *	Input: "III"	Output: 3
	 *	Input: "IV"	Output: 4
	 *	Input: "IX"	Output: 9
	 *	Input: "LVIII"	Output: 58  Explanation: L = 50, V= 5, III = 3.
	 *	Input: "MCMXCIV"Output: 1994
	 *	Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
	 *=====================================================================
	 */
	int romanToInt(std::string s) {
		std::unordered_map<char, int> lut{{'I', 1}, {'V', 5},
						  {'X', 10}, {'L', 50},
						  {'C', 100}, {'D', 500},
						  {'M', 1000}};
		
		int result = 0;
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			if (i+1 < len && lut[s[i]] < lut[s[i+1]]) {
				result -= lut[s[i]];
				continue;
			}
			result += lut[s[i]];
		}
		
		return result;
	}

	// 12. Integer to Roman
	/*=====================================================================
	 * Description: The same as above
	 * Example:
	 *	Input: 3	Output: "III"
	 *	Input: 4	Output: "IV"
	 *	Input: 9	Output: "IX"
	 *	Input: 58	Output: "LVIII"
	 *	Explanation: L = 50, V = 5, III = 3.
	 *
	 *	Input: 1994	Output: "MCMXCIV"
	 *	Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
	 *=====================================================================
	 */
	std::string intToRoman(int num) {
		std::string ret;
		if (num < 1 || num > 3999) return ret;
		
		std::vector<std::pair<char, int>> lut{{'I', 1}, {'V', 5},
						      {'X', 10}, {'L', 50},
						      {'C', 100}, {'D', 500},
						      {'M', 1000}};
		
		for (int i = lut.size()-1; i >= 0; i -= 2) {
			int tmp = num / lut[i].second;
			num %= lut[i].second;
			
			if (9==tmp || 4==tmp) {
				ret += lut[i].first;
				ret += (9==tmp ? lut[i+2].first :
					lut[i+1].first);
			} else if (tmp > 0) {
				if (tmp >= 5) {
					ret += lut[i+1].first;
					tmp -= 5;
				}
				while(tmp--) {
					ret += lut[i].first;
				}
			}
		}
		
		return ret;
	}
};

int main(int argc, char *argv[]) {
	Solution solver;

	std::string str = "MCMXCIV";
	int ret = solver.romanToInt(str);
	std::string rev = solver.intToRoman(ret);

	std::cout << "original Roman string: " << str << std::endl;
	std::cout << "transfered int: " << ret << std::endl;
	std::cout << "the reversed roman string: " << rev << std::endl;

	return 0;
}

