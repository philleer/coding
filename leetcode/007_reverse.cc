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

#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    /*============================================================
     * Description: Given a 32-bit signed integer, reverse digits
     *              of an integer.
     * Example 1:  Input: 123  Output: 321
     * Example 2:  Input: -123 Output: -321
     * Example 3:  Input: 120  Output: 21
     * Note:   Assume we are dealing with an environment which
     * could only store integers within the 32-bit signed integer
     * range: [−231,  231 − 1].
     * For the purpose of this problem, assume that your function
     * returns 0 when the reversed integer overflows.
     *============================================================
     */
    int reverse(int x) {
        if (x - 0x80000000 > 0 && x <= 0x7fffffff) {
            int flag = (x < 0) ? -1 : 1;
            x *= (x < 0) ? -1 : 1;

            long long res = 0;
            while ((x / 10) || (x % 10)) {
                res = 10 * res + x % 10;
                x /= 10;
                if (res > 0x7fffffff)
                    res = 0;
            }

            return (flag == 1) ? res : -res;
        }
        else {
            return 0;
        }
    }
};

int main(int argc, char** argv) {
    int x = -1;
    scanf("%d", &x);

    Solution solver;
    int res = solver.reverse(x);
    printf("The original number is:%d\n", x);
    printf("The result number is: %d\n", res);

    return 0;
}