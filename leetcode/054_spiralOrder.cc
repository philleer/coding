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
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

class Solution {
public:
	// 54. Spiral Matrix
	/*=====================================================================
	 * Description: Given a matrix of mxn elements (m rows, n columns), 
	 *	return all elements of the matrix in spiral order.
	 * Example:
	 *	Input: [[ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ]]
	 *	Output: [1,2,3,6,9,8,7,4,5]
	 *
	 *	Input: [[1, 2, 3, 4], [5, 6, 7, 8], [9,10,11,12]]
	 *	Output: [1,2,3,4,8,12,11,10,9,5,6,7]
	 *=====================================================================
	 */
	// 从原始矩阵的结构出发进行求解，按行列遍历放到结果数组的指定位置
	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
		std::vector<int> res;
		int m = matrix.size();
		if (m <= 0) return res;
		if (1 == m) {
			res.assign(matrix[0].begin(), matrix[0].end());
			return res;
		}
		int n = matrix[0].size();
		if (1 == n) {
		    for (int i = 0; i < m; ++i) res.push_back(matrix[i][0]);
		    return res;
		}
		res.resize(m*n);

		int cnt = 0, start = 0;
		int count = std::min(m/2+m^1, n/2+n^1);
		while (cnt < count) {
			int row = m - 2*cnt;
			int col = n - 2*cnt;
			int index = start;
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					if (0 == i) {
						res[index++] =
							matrix[i+cnt][j+cnt];
						continue;
					}
					if (row > 1 && row-1==i) {
						index = start+col*2+row-3-j;
					} else if (i>0 && i<row-1 && 0==j) {
						if (col > 1) {
							index =
							start+col*2+row*2-i-4;
						} else {
							index =
							start+col*2+row-i-3;
						}
					} else if (i>0 && i<row-1 && col>1 &&
						   col-1==j)
					{
						index = start+col+i-1;
					} else {
						continue;
					}
				
					res[index] = matrix[i+cnt][j+cnt];
				}
			}
			++cnt;
			start += (row+col)*2-4;
		}

		return res;
	}

	// Solution from the forume
	// 大佬的做法果然清爽非凡，从结果数组出发，一个一个依序填充，直接去找
	// 原始矩阵中的相应元素
	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
		std::vector<int> res;
		int row = matrix.size();
		if(0 == row) return res;
		int col = matrix[0].size();

		int r = 0, c = 0;
		while(r < row && c < col) {
			for(int i=c; i<col; ++i) res.push_back(matrix[r][i]);
			++r;
			
			for(int i=r; i<row; ++i)
				res.push_back(matrix[i][col-1]);
			--col;
			
			if (r < row) {
				for(int i=col-1; i>=c; --i)
					res.push_back(matrix[row-1][i]);
				--row;
			}
			
			if(c < col) {
				for(int i=row-1; i>=r; --i)
					res.push_back(matrix[i][c]);
				++c;
			}
		}
		return res;
	}

	// 59. Spiral Matrix II
	/*=====================================================================
	 * Description: Given a positive integer n, generate a square matrix
	 *	filled with elements from 1 to n2 in spiral order.
	 *
	 * Example:
	 *	Input: 3
	 *	Output: [[ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ]]
	 *=====================================================================
	 */
	std::vector<std::vector<int>> generateMatrix(int n) {
		std::vector<std::vector<int>> res;
		if (n <= 1) {
			if (1 == n) {
				std::vector<int> tmp{1};
				res.push_back(tmp);
			}
			return res;
		}

		res.resize(n);
		for (int i = 0; i < n; ++i) res[i].resize(n);

		int cnt = 0, start = 1;
		int count = n/2 + n^1;
		while (cnt < count) {
			int row = n - 2*cnt;
			for (int i = 0; i < row; ++i) {
				res[0+cnt][i+cnt] = start+i;
				res[row-1+cnt][i+cnt] = start+(row-1)*3-i;
				if (i > 0 && i < n-1) {
					res[i+cnt][0+cnt] = start+(row-1)*4-i;
					res[i+cnt][row-1+cnt] = start+row-1+i;
				}

			}
			start += (row-1)*4;
			++cnt;
		}

		return res;
	}
};

int main(int argc, char const *argv[]) {
	int NUM = 1;
	// 设置此处的NUM的值，当其为1时表示测试函数 spiralOrder
	// 当其为2时测试函数 generateMatrix
	switch (NUM) {
	case 1: {
		// Test the spiral matrix I
		std::string line;
		// 输入格式：将整个矩阵一次性按行输入，行与行之间用分号隔开，
		// 元素与元素之间空格隔开 如 1 2 3 4;5 6 7 8;9 10 11 12;
		while (std::getline(std::cin, line)) {
			std::stringstream ss;
			ss.str(line);
			std::string str;
			std::vector<std::string> strs;
			while (std::getline(ss, str, ';')) {
				strs.emplace_back(str);
			}

			std::vector<std::vector<int>> nums;
			for (int i = 0; i < strs.size(); ++i) {
				std::stringstream ssnum;
				ssnum.str(strs[i]);
				std::vector<int> tmp;
				// 由于从stringstream中截取字符串只能赋值
				// 给char或string类型，所以再将其转换成相
				// 应的整型，利用函数atoi
				// 该函数包含在 <cstdlib> 头文件中
				std::string chs;
				while (std::getline(ssnum, chs, ' ')) {
					tmp.push_back(std::atoi(
						      chs.c_str()));
				}
				nums.emplace_back(tmp);
			}

			std::vector<int> res =
				Solution().spiralOrder(nums);
			std::cout << "The initialized matrix is:\n["
				<< std::endl;
			for (int i = 0; i < nums.size(); ++i) {
				std::cout << "  [ ";
				for (int j=0; j < nums[i].size(); ++j) {
					std::cout << nums[i][j] << " ";
				}
				std::cout << "]" << std::endl;
			}
			std::cout << "]" << std::endl;

			std::cout << "The result vector is:\n[ ";
			for (auto &num : res) {
				std::cout << num << " ";
			}
			std::cout << "]" << std::endl;
		}
		break;
	}
	case 2: {
		// Test the spiral matrix II
		std::string line;
		// 输入格式：只有一个整数n，随便怎么输入都行
		while (std::getline(std::cin, line)) {
			std::stringstream ss;
			ss.str(line);
			int n;
			ss >> n;
			std::vector<std::vector<int>> res =
				Solution().generateMatrix(n);
			std::cout << "n = " << n << std::endl;
			std::cout << "The result vector is:\n[ ";
			for (int i = 0; i < res.size(); ++i) {
				std::cout << "  [ ";
				for (int j=0; j < res[i].size(); ++j) {
					std::cout << res[i][j] << " ";
				}
				std::cout << "]" << std::endl;
			}
			std::cout << "]" << std::endl;
		}
		break;
	}
	default: break;
	}
	
	return 0;
}
