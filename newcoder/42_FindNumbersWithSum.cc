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

class Solution {
public:
    /*=============================================================
     * 题目描述: 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
     *          使得他们的和正好是S，如果有多对数字的和等于S，输出两个
     *          数的乘积最小的。对应每个测试案例，输出两个数，小的先输出。
     * 例如:  如果输入数组{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,
     *          18,19,20}, sum = 21
     *          对应的输出是1,20
     *=============================================================
     */    
    vector<int> FindNumbersWithSum(vector<int> &array,int sum) {
        vector<int> res;
        if (array.empty())
            return res;
        
        int mul = 0x7fffffff;
        int temp = 0;
        for (int i = 0; i < array.size(); i++) {
            for (int j = i + 1; j < array.size(); j++) {
                if (array[i] + array[j] == sum) {
                    temp = array[i] * array[j];
                    
                    if (temp < mul) {
                        mul = temp;
                        if (res.empty()) {
                            res.push_back(array[i]);
                            res.push_back(array[j]);
                        }
                        else {
                            res[0] = array[i];
                            res[1] = array[j];
                        }
                    }
                }
            }
        }
        
        return res;
    }
};

int main(int argc, char **argv) {
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int length = sizeof(array)/sizeof(array[0]);
    vector<int> vectemp;
    vectemp.assign(array, array+length);
    int sum = 23;

    Solution solver;
    vector<int> result = solver.FindNumbersWithSum(vectemp, sum);
    printf("The result is:\n\t");
    for (int i = 0; i < result.size(); i++)
        printf("%d ", result[i]);
    printf("\n");

    return 0;
}