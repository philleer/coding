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

#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    /*===============================================================
     * Description: Implement pow(x, n), which calculates x raised 
     * 			to the power n (xn).
     * Example 1:	Input: 2.00000, 10	Output: 1024.00000
     * Example 2:	Input: 2.10000, 3	Output: 9.26100
     * Example 3:	Input: 2.00000, -2	Output: 0.25000
     * Explanation: 2-2 = 1/22 = 1/4 = 0.25
     * Note:	-100.0 < x < 100.0
     *		n is 32-bit signed integer, in range [−231, 231 − 1]
     *===============================================================
     */
    // 递归求解，每次将幂减半，如果是奇数将结果在乘一次自身的值
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        // 这里的0x80000000表示32位整数可以表示的最小值，也即-2147483648
        // 在VS2010中比较输入的n与0x80000000的大小时，直接利用n>0x80000000
        // 输出的结果与预期不同，并不能得到正确结果，因而此处使用了一个小trick
        // 利用n-0x80000000>0进行这样的运算
        // 而正整数可以直接比较，2147483647表示32位有符号整数的最大值2147483647
        // -0x80000000 -- 0x7fffffff
        if ((n - 0x80000000 > 0 && n <= 0x7fffffff) &&
            (x + 100.0 >= 0 && x <= 100.0)) {
            int flag = n < 0 ? 1 : 0;
            n *= n < 0 ? -1 : 1;

            double res = 1;
            res = myPow(x, n >> 1);
            res *= res;
            res *= (n & 1) ? x : 1;
            res = flag == 1 ? 1/res : res;

            return res;
        }
        else
            // 如果底为1，则其任何幂此结果都为1
            // 如果底为-1，则偶次幂结果为1，奇次幂结果为-1
            return (x == 1 || x == -1) ? 
                    ((x==-1) ? ((n & 1) ? -1 : 1) : 1) : 0;
    }
};

int main(int argc, char** argv) {
    double x = 0;
    int n = 0;
    printf("input double x and integer power n:\n");
    // 注意scanf函数与printf函数的区别
    // 当要处理的数据为double型时，scanf的符号参数为lf
    // 而printf的符号参数为f，表示从栈中取四个字节的内容
    scanf("%lf %d", &x, &n);

    Solution solver;
    printf("\nthe result is: \t%f\n", solver.myPow(x, n));
    return 0;
}

