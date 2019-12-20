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
// 38. Count and Say
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
	/*=====================================================================
	 * Description: The count-and-say sequence is the sequence of integers
	 *	with the first five terms as following:
	 *		1.     1
	 *		2.     11
	 *		3.     21
	 *		4.     1211
	 *		5.     111221
	 * Note:
	 *	the (i+1)th sequence is the "count and say" of the ith sequence!
	 *
	 * Example:
	 * 		Input: 1 	Output: "1"
	 *		Input: 4 	Output: "1211"
	 *=====================================================================
	 */
	std::string countAndSay(int n) {
		if (n < 1 || n > 30) return "";

		int k = 1;
		std::string result("1");
		while (k++ < n) {
			int count = 1;
			std::string s;
			for (int i = 0; i < result.size(); ++i) {
				if (0 != i) {
					if (result[i] == result[i-1]) {
						++count;
					} else {
						s.push_back(count+'0');
						s.push_back(result[i-1]);
						count = 1;
					}
				}

				if (result.size()-1 == i) {
					s.push_back(count+'0');
					s.push_back(result[i]);
				}
			}
			result = s;
		}

		return result;
	}

	std::string countAndSayRecursively1(int n) {
		if (n == 1)  return "1";
		
		int count = 1;
		std::string pre = countAndSayRecursively1(--n);
		std::string res = "";

		for (int i = 0; i < pre.size(); ++i){
			if (i+1 < pre.size() && pre[i] == pre[i+1]) {
				++count;
			} else {
				res += (count + '0');
				res += pre[i];
				count = 1;
			}
		}

		return res;
	}
};

int main(int argc, const char *argv[]) {
	int n = 4;
	std::cout << "The " << n << "th sequence is: "
		<< Solution().countAndSay(n) << std::endl;

	return 0;
}