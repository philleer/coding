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
#include <assert.h>

class Solution {
public:
	// 537. Complex Number Multiplication
	/*=====================================================================
	 * Description: Given two strings representing two complex numbers. You
	 *	need to return a string representing their multiplication. Note
	 *	i2 = -1 according to the definition.
	 *
	 * Example:
	 *	Input: "1+1i", "1+1i"	Output: "0+2i"
	 *	Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you
	 *	need convert it to the form of 0+2i.
	 *	
	 *	Input: "1+-1i", "1+-1i"	Output: "0+-2i"
	 *	Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you
	 *	need convert it to the form of 0+-2i.
	 * Note:
	 *	The input strings will not have extra blank.
	 *	The input strings will be given in the form of a+bi, where the
	 *	integer a and b will both belong to the range of [-100, 100].
	 *	And the output should be also in this form.
	 *=====================================================================
	 */
	int find_position(std::string &s, char c) {
		for (int i = 0; i < s.length(); ++i) {
			if (c == a[i]) return (i+1);
		}
		return -1;
	}
	
	std::string complexNumberMultiply(std::string a, std::string b) {
		if (a.empty() || b.empty()) {
			return (a.empty() ? b : a);
		}

		int pos = find_position(a, '+');
		int a1, b1, a2, b2;
		std::stringstream ss;
		std::string tmp_str = a.substr(0, pos);
		ss.str(tmp_str);
		ss >> a1;
		tmp_str = a.substr(pos);
		ss.str(tmp_str);
		ss >>b1;

		pos = find_position(b, '+');
		tmp_str = b.substr(0, pos);
		ss.str(tmp_str);
		ss >> a2;
		tmp_str = b.substr(pos);
		ss.str(tmp_str);
		ss >> b2;

		std::string res = std::to_string(a1*a2-b1*b2) + "+" +
				  std::to_string(a1*b2+a2*b1) + "i";
		return res;
	}
};

std::string stringToString(std::string input) {
	assert(input.length() >= 2);
	std::string result;
	for (int i = 1; i < input.length() -1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i+1];
			switch (nextChar) {
				case '\"': result.push_back('\"'); break;
				case '/' : result.push_back('/'); break;
				case '\\': result.push_back('\\'); break;
				case 'b' : result.push_back('\b'); break;
				case 'f' : result.push_back('\f'); break;
				case 'r' : result.push_back('\r'); break;
				case 'n' : result.push_back('\n'); break;
				case 't' : result.push_back('\t'); break;
				default: break;
			}
			i++;
		} else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main(int argc, char *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::string a = stringToString(line);
		std::getline(std::cin, line);
		std::string b = stringToString(line);

		std::string ret = Solution().complexNumberMultiply(a, b);
		std::cout << ret << std::endl;
	}
	return 0;
}

