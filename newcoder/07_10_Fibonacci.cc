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
	/*==========================================================
	 * 题目描述：要求输入一个整数n，输出斐波那契数列的第n项（第0项为0）
	 * 			n<=39
	 *==========================================================
	 */
	// 使用递推来代替递归调用，节省了很多不必要的计算
    int Fibonacci(int n) {
    	// 基准情形
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        
        int f1 = 0;
        int f2 = 1;
        int res = 1;
        // 递推公式
        for (int i = 1; i < n; i++) {
            res = f1 + f2;
            f1 = f2;
            f2 = res;
        }
        return res;
    }

	/*==========================================================
	 * 题目描述：一只青蛙一次可以跳1级台阶，也可以跳2级。求该青蛙跳一个
	 * 			n级的台阶总共有多少种跳法（先后次序不同算不同的结果）
	 *==========================================================
	 */
    // 未优化的递归公式，计算冗余度太高使得n较大时计算速度十分慢
    int jumpFloor(int n) {
        // 基准情形
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        // 递推公式
        return jumpFloor(n-1)+jumpFloor(n-2);
    }

    /*==========================================================
	 * 题目描述：一只青蛙一次可以跳1级台阶，也可以跳2级……也可以跳n级。
	 * 			求该青蛙跳上一个n级的台阶总共有多少种跳法。
	 *==========================================================
	 */
    // 因为是int型数据的保存需要n < 32
    // 当n = 32时，res左移31位得到0x80000000也即是-2147483648
    // f(n) = f(n-1) + f(n-2) +...+ f(1)
    // f(n-1) = f(n-2) + f(n-3) +...+ f(1)
    // ==> f(n) = f(n-1) + (f(n-2)+f(n-3)+...+f(1)) = 2 * f(n-1)
    int jumpFloorII(int n) {
        if (n <= 0)
            return 0;
        
        int res = 1;
        return res << (n - 1);
    }

    /*==========================================================
	 * 题目描述：我们可以用2*1的小矩形横着或竖着去覆盖更大的矩形。请问
	 * 			用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，共有多
	 * 			少种方法？
	 *==========================================================
	 */
    // the problem can be abstracted as fibonacci
    int rectCover(int n) {
        if (n <= 0)
            return 0;
        if (n == 2)
            return 2;
        
        int f1 = 1;
        int f2 = 2;
        int res = f1;
        while (n-- >= 3) {
            res = f1 + f2;
            f1 = f2;
            f2 = res;
        }
        
        return res;
    }    
};

int main(int argc, char **argv) {
	int n = 0;
	Solution solver;
	printf("input an integer n:\n");
	scanf("%d", &n);
	printf("The result is:\n%d\n", solver.Fibonacci(n));

	printf("input an integer n:\n");
	scanf("%d", &n);
	printf("The result is:\n%d\n", solver.jumpFloor(n));

	printf("input an integer n:\n");
	scanf("%d", &n);
	printf("The result is:\n%d\n", solver.jumpFloorII(n));

	printf("input an integer n:\n");
	scanf("%d", &n);
	printf("The result is:\n%d\n", solver.rectCover(n));

	return 0;
}