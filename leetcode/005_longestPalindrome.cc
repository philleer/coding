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
#include <string>
#include <cstdio>

class Solution {
public:
    /*=========================================================================
     * Description:	Given a string s, find the longest palindromic substring in
     * 			s. You may assume the maximum	length of s is 1000.
     *
     * Example :
     *      Input: "babad"	Output: "bab"
     * 			Explination: "aba" is also a valid answer.
     *
     *      Input: "cbbd"	Output: "bb"
     *=========================================================================
     */	
    std::string longestPalindrome(std::string s) {
        std::string res;
        if (s.empty()) return res;
        
        int len = s.length();
        int tmpLen = 0, maxLen = 0;
        int start = 0;
        
        // for palindrome like abba
        for (int ii = 0; ii < len; ii++) {
            tmpLen = 0;
            for (int jj = 0; (jj <= ii) && (jj < (len - ii - 1)); jj++) {
                if (s[ii - jj] == s[ii + 1 + jj]) {
                    tmpLen = jj * 2 + 2;
                    if (tmpLen > maxLen) {
                        maxLen = tmpLen;
                        start = ii - jj;
                    }
                } else {
                    break;
                }
            }
        }
        
        // for palindrome like bab
        for (int i = 1; i < len - 1; i++) {
            tmpLen = 0;
            for (int j = 1; (j <= i) && (j < len - i); j++) {
                if (s[i - j] == s[i + j]) {
                    tmpLen = j * 2 + 1;
                    if (tmpLen > maxLen) {
                        maxLen = tmpLen;
                        start = i - j;
                    }
                } else {
                    break;
                }
            }
        }
        
        res = s.substr(start, maxLen);
        // if there is no palindrome existing in the given string
        // then return the first character of s
        if (res.empty()) res = s.substr(0, 1);
            
        return res;
    }
};

int main(int argc, char *argv[]) {
	std::string str1 = "babad";
	std::string str2 = "cbbd";
	std::string str3 = "abcda";
	std::string str4 = "";
	printf("the given string is shown as:\n");
	printf("\tstr1 = %s\n", str1.c_str());
	printf("\tstr2 = %s\n", str2.c_str());
	printf("\tstr3 = %s\n", str3.c_str());
	printf("\tstr4 = %s\n", str4.c_str());

	Solution solver;
	std::string result = solver.longestPalindrome(str1);
	printf("\nthe result substring is shown as:\n");
	printf("\tresult = %s", result.c_str());

	result = solver.longestPalindrome(str2);
	printf("\nthe result substring is shown as:\n");
	printf("\tresult = %s", result.c_str());

	result = solver.longestPalindrome(str3);
	printf("\nthe result substring is shown as:\n");
	printf("\tresult = %s", result.c_str());

	result = solver.longestPalindrome(str4);
	printf("\nthe result substring is shown as:\n");
	printf("\tresult = %s", result.c_str());

	return 0;
}

