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
#include <cstdio>
#include <string>

class Solution {
public:
	/*=====================================================================
	 * Description: The string "PAYPALISHIRING" is written in a zigzag
	 *	pattern on a given number of rows like this: (you may want to
	 *	display this pattern in a fixed font for better legibility)
	 *              P   A   H   N
	 *              A P L S I I G
	 *              Y   I   R
	 *	And then read line by line: "PAHNAPLSIIGYIR", Write the code
	 *	that will take a str and make this conversion given a number of
	 *	rows:
	 *		string convert(string s, int numRows);
	 * Example :
	 * 	Input: s = "PAYPALISHIRING", numRows = 3
	 *	Output: "PAHNAPLSIIGYIR"
	 *
	 * 	Input: s = "PAYPALISHIRING", numRows = 4
	 *	Output: "PINALSIGYAHRPI"
	 * 	Explanation:	P     I    N
	 *      	        A   L S  I G
	 *      	        Y A   H R
	 *			P     I
	 *=====================================================================
	 */
	std::string convert(std::string s, int numRows) {
		std::string res;
		if (s.empty() || numRows <= 1) return s;
		
		int index = 0;
		int tmp = (numRows - 1) * 2;
		for (int i = 0; i < numRows; i++) {
			int j = 0;
			index = i;
			
			while (index < s.length()) {
				res += s[index];
				++j;
				if (i>=1 && i<numRows-1) {
					if ((tmp*j+i) > (tmp*(j-1)+tmp-i)) {
						index = tmp*(j-1)+tmp-i;
						if (index < s.length())
							res += s[index];
					}
				}
				index = tmp * j + i;
			}
		}
		
		return res;
	}
};

int main(int argc, const char *argv[]) {
	std::string str = "PAYPALISHIRING";
	printf("the given string is shown as:\n\t");
	printf("str = %s\n", str.c_str());
	
	// int rows = 0;
	// printf("input the num of rows:\n");
	// scanf("%d", &rows);
	
	Solution solver;
	std::string result = solver.convert(str, 3);
	printf("\nthe result string is shown as:\n\t");
	printf("result = %s\n", result.c_str());
	
	/** TODO **/
	// print the zigzag format of the result
	// just like the explanation above
	
	return 0;
}

