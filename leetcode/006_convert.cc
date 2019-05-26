// This file is part of my coding practice, a lightweight C++
// solution for newcoder program practice.
//
// For all of files in the coding folder, I check the rightness
// not only by the case test online, but also by my offline IDE
// Microsoft Visual Studio 2010 as well when I write on windows
// 7 64-bit platform or by g++5.4 when I am on linux platform.
// 
// If there are some questions, please send me an email: 
// Phil <phillee2016@163.com> or feel free to create an issue.

#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    /*
     * Description: The string "PAYPALISHIRING" is written in a zigzag
     *              pattern on a given number of rows like this: (you
     *              may want to display this pattern in a fixed font
     *              for better legibility)
     *              P   A   H   N
     *              A P L S I I G
     *              Y   I   R
     *              And then read line by line: "PAHNAPLSIIGYIR"
     *              Write the code that will take a string and make this
     *              conversion given a number of rows:
     *              string convert(string s, int numRows);
     * Example 1:   Input: s = "PAYPALISHIRING", numRows = 3
     *              Output: "PAHNAPLSIIGYIR"
     * Example 2:   Input: s = "PAYPALISHIRING", numRows = 4
     *              Output: "PINALSIGYAHRPI"
     * Explanation: P     I    N
     *              A   L S  I G
     *              Y A   H R
     *              P     I
     */
    string convert(string s, int numRows) {
        string res;
        if (s.empty() || numRows <= 1)
            return s;
        
        int index = 0;
        int tmp = (numRows - 1) * 2;
        
        for (int i = 0; i < numRows; i++) {
            int j = 0;
            index = i;

            while (index < s.length()) {
                res += s[index];
                ++j;
                if ((i >= 1) && (i < numRows - 1)) {
                    if ((tmp * j + i) > (tmp * (j - 1) + tmp -i)) {
                        index = tmp * (j - 1) + tmp -i;
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

int main(int argc, char **argv) {
    string str = "PAYPALISHIRING";
    printf("the given string is shown as:\n\t");
    printf("str = %s\n", str.c_str());

    // int rows = 0;
    // printf("input the num of rows:\n");
    // scanf("%d", &rows);

    Solution solver;
    string result = solver.convert(str, 3);
    printf("\nthe result string is shown as:\n\t");
    printf("result = %s\n", result.c_str());

    /** TODO **/
    // print the zigzag format of the result
    // just like the explanation above

    return 0;
}