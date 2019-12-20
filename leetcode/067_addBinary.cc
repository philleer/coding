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
#include <vector>

class Solution {
public:
	// 58. Length of Last Word
	/*=====================================================================
	 * Description: Given a string s consists of upper/lower-case alphabets
	 *	and empty space characters ' ', return the length of last word
	 *	in the string. If the last word does not exist, return 0.
	 *
	 * Note:
	 *	A word is defined as a character sequence consists of non-space
	 *	characters only.
	 *
	 * Example:
	 *	Input: "Hello World"	Output: 5
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

	// 67. Add Binary
	/*=====================================================================
	 * Description: Given two binary strings, return their sum (also a
	 *	binary string).
	 *	The input strings are both non-empty and contains only
	 *	characters 1 or 0.
	 *
	 * Example:
	 *	Input: a = "11", b = "1"	Output: "100"
	 *	Input: a = "1010", b = "1011"	Output: "10101"
	 *=====================================================================
	 */
	std::string addBinary(std::string a, std::string b) {
		if (a.empty() || b.empty()) return (a.empty() ? b : a);

		std::string res;
		a.swap(b);

		int flag = 0, sum = 0;
		int idx = a.length()-1, len = b.length();
		for (int i = len-1; i >= 0; --i) {
			sum = (a[idx+1-len+i]-'0') + (b[i]-'0') + flag;
			flag = (sum>=2 ? 1 : 0);
			if (sum >= 2) sum -= 2;
			res.insert(res.begin(), 1, sum+'0');
		}

		for (int i = idx-len; i >= 0; --i) {
			sum = (a[i]-'0') + flag;
			flag = (sum>=2 ? 1 : 0);
			if (sum >= 2) sum -= 2;
			res.insert(res.begin(), 1, sum+'0');
		}

		if (1 == flag) res.insert(res.begin(), 1, '1');

		return res;
	}

	// 69. Sqrt(x)
	/*=====================================================================
	 * Description: Implement int sqrt(int x). Compute and return the
	 *	square root of x, where x is guaranteed to be a non-negative
	 *	integer.
	 *	Since the return type is an integer, the decimal digits are
	 *	truncated and only the integer part of the result is returned.
	 *
	 * Example:
	 *	Input: 4	Output: 2
	 *
	 *	Input: 8	Output: 2
	 *	Explanation: The square root of 8 is 2.82842..., and since the
	 *	decimal part is truncated, 2 is returned.
	 *=====================================================================
	 */
        int mySqrt(int x) {
		if (x <= 0) return 0;
		if (1 == x) return x;

		long long res = 1;
		// 46340.9 * 46340.9 = MAX_INT
		// 还可以写成 res <= x/res
		while (res <= 46340 && res*res <= x) res += 1;

		return res-1;
	}
};

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::string tmp;
		std::vector<std::string> strs;
		// 输入时保持用逗号隔开的格式
		while(std::getline(ss, tmp, ',')) {
			strs.push_back(tmp);
		}

		// The given binary in string format
		for (auto &str : strs) std::cout << str << std::endl;
		std::cout << "The additiion: " <<
			Solution().addBinary(strs[0], strs[1]) << std::endl;
	}
	return 0;
}

