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
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*=============================================================
     * 题目描述: 在一个长度为n的数组里所有数字都在0到n-1范围内。数组中某
     *          些数字是重复的，但不知道有几个数字是重复的。也不知道每个
     *          数字重复几次。请找出数组中任意一个重复的数字。
     * 例如:   如果输入长度为7的数组{2,3,1,0,2,5,3}
     *         对应的输出是第一个重复的数字2
     *=============================================================
     */
     // Parameters:
     //        numbers:     an array of integers
     //        length:      the length of array numbers
     //        duplication: (Output)duplicated number from input
     // Return value:       true if the input is valid, and there
     //                     are some duplications in the array number
     //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int index = 0;
        if (length > 0) {
            for (int i = 0; i < length; i++) {
                for (int j = i + 1; j < length; j++) {
                    if (numbers[j] == numbers[i])
                        duplication[index++] = numbers[i];
                }
                if (index > 0)
                    break;
            }
        }

        return (index > 0) ? true : false;
    }

    bool duplicate2(int numbers[], int length, int* duplication) {
        unordered_map<int, int> m;
        
        int index = 0;
        if (length > 0) {
            for (int i = 0; i < length; i++) {
                if (!m.count(numbers[i])) {
                    m.insert(make_pair(numbers[i], i));
                }
                else {
                    duplication[index++] = numbers[i];
                }
                if (index > 0)
                    break;
            }
        }
        
        return (index > 0) ? true : false;
    }
};

int main(int argc, char **argv) {
    int array[] = {2,3,1,0,2,5,3};
    int length = sizeof(array)/sizeof(array[0]);
    int* result = new int[length];
    for (int i = 0; i < length; i++)
        result[i] = -1;

    Solution solver;
    bool sign = solver.duplicate(array, length, result);
    printf("The duplicated numbers are:\n");
    for (int i = 0; i < length && sign; i++)
        if(result[i] >=0 && result[i] < length)
            printf("%d ", result[i]);
    printf("\n");

    return 0;
}