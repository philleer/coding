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
#include <string>
#include <cstdio>
#include <exception>

using namespace std;

class Solution {
public:
	/* 题目描述：把一个数组最开始的若干个元素搬到数组的末尾，
	 * 我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，
	 * 输出旋转数组的最小元素。
	 * 示例：输入数组{3,4,5,1,2}， 输出1
	 * 解释：输入的数组是{1,2,3,4,5}的一个旋转，最小值为1。
	 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
	 */
    int minNumberInRotateArray(vector<int> &rotateArray) {
        if (rotateArray.empty())
        	throw runtime_error("Empty array, invalid!");

    	int low = 0;
    	int high = rotateArray.size() - 1;
    	int mid = low;
		
		// if the array is not standard rotate array
		// just return rotateArray[0]
		if (rotateArray[low] > rotateArray[high]) {
			while (low < high) {
				if (high - low == 1) {
					mid = high;
					break;
				}
				mid = (low + high) / 2;		
				if (rotateArray[low] < rotateArray[mid]) {
					low = mid;
				}
				else if (rotateArray[low] > rotateArray[mid]) {
					high = mid;
				}
			}
		}
		else if (rotateArray[low] == rotateArray[high]) {
			while (low < high) {
				if (high - low == 1) {
					mid = high;
					break;
				}
				mid = (low + high) / 2;
				if (rotateArray[mid] > rotateArray[high])
					low++;
				else
					high--;
			}
		}

    	return rotateArray[mid];
    }

	// 注意到上面有一部分是重复的，可以优化一下
    int minNumberInRotateArrayRefined(vector<int> &rotateArray) {
		if (rotateArray.empty())
			throw runtime_error("Empty array, invalid!");

		int low = 0;
		int high = rotateArray.size() - 1;
		int mid = low;

		if (rotateArray[low] >= rotateArray[high]) {
			while (low < high) {
				if (high - low == 1) {
					mid = high;
					break;
				}
				mid = (low + high) / 2;

				if (rotateArray[low] < rotateArray[mid]) {
					low = mid;
				}
				else if (rotateArray[low] > rotateArray[mid]) {
					high = mid;
				}
				else {
					if (rotateArray[mid] > rotateArray[high])
						low++;
					else
						high--;
				}
			}			
		}

		return rotateArray[mid];
	}

	// 剑指offer上给的解法，不太好撸
    int minNumberInRotateArrayOffer(vector<int> &rotateArray) {
    	if (rotateArray.empty())
    		throw runtime_error("Empty array, invalid!");

    	int low = 0;
    	int high = rotateArray.size() - 1;
    	int mid = low;
    	while (rotateArray[low] >= rotateArray[high]) {
    		if (high - low == 1) {
    			mid = high;
    			break;
    		}

    		mid = (low + high) / 2;
    		// 如果下标low、high、mid指向的元素均相等
    		// 则只能顺序查找
    		if (rotateArray[low] == rotateArray[high]
    			&& rotateArray[low] == rotateArray[mid]) {
    			mid = low;
    			for (int i = low + 1; i < high; i++) {
    				if (rotateArray[i] < rotateArray[mid])
    					mid = i;
    			}
    			return rotateArray[mid];
    		}

    		if (rotateArray[mid] >= rotateArray[low])
    			low = mid;
    		else if (rotateArray[mid] <= rotateArray[high])
    			high = mid;
    	}

    	return rotateArray[mid];
    }

    // 简单粗暴，非常好用
    int minNumberInRotateArraySelect(vector<int> &rotateArray) {
    	if (rotateArray.empty())
    		throw runtime_error("Empty array, invalid!");

    	int min = 0;
    	for (int i = 1; i < rotateArray.size(); i++) {
    		if (rotateArray[i] < rotateArray[min])
    			min = i;
    	}

    	return rotateArray[min];
    }
};

int main(int argc, char **argv) {
	int array[] = {3,4,5,1,2};	// {2,1}, {1,0,1,1,1}, {1,1,1,0,1}
	int length = sizeof(array) / sizeof(array[0]);
	vector<int> vectortmp;
	vectortmp.assign(array, array+length);

	printf("The input array is:\n\t");
	for (int i = 0; i < length; i++)
		printf("%d ", vectortmp[i]);
	printf("\n");

	Solution solver;
	int min = solver.minNumberInRotateArray();
	printf("The minimum number of the Rotate Array is: %d\n", min);
	return 0;
}