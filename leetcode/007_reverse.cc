<<<<<<< HEAD
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
=======
// The source is part of my coding practice, a lightweight C++
// solution for leetcode program practice.
//
// For all of my code, after check it online by submit, I also compile
// and run it by my offline IDE 
// ===================================================================
// ********* Microsoft Visual Studio 2010 when I use windows *********
// *********           G++5.4.0 when I am on Linux           *********
// ===================================================================
//
// If any question, feel free to send me an email
// phillee2016@163.com
// or just correct it via Pull Request or create an issue.

>>>>>>> 7fe4ff2... find the longest palindromic sub-string
#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
        // 007.reverse
        /*=====================================================================
         * Description: Given a 32-bit signed integer, reverse digits of an int.
         *
         * Example:
         *      Input: 123  Output: 321
         *      Input: -123 Output: -321
         *      Input: 120  Output: 21
         * Note:
         *      Assume we are dealing with an environment which could only
         *      store integers within the 32-bit signed integer range: [−2^31,
         *      2^31 − 1].
         *      For the purpose of this problem, assume that your function
         *      returns 0 when the reversed integer overflows.
         *=====================================================================
         */
        int reverse(int x) {
                if (x - 0x80000000 > 0 && x <= 0x7fffffff) {
                        int flag = (x < 0) ? -1 : 1;
                        x *= (x < 0) ? -1 : 1;

                        long long res = 0;
                        while ((x / 10) || (x % 10)) {
                                res = 10 * res + x % 10;
                                x /= 10;
                                if (res > 0x7fffffff) res = 0;
                        }

                        return (flag == 1) ? res : -res;
                } else {
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

<<<<<<< HEAD
=======
    return 0;
}
>>>>>>> 7fe4ff2... find the longest palindromic sub-string
