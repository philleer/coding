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
#include <string>

class Solution {
public:
	// 48. Rotate Image
	/*=====================================================================
	 * Description: You are given an n x n 2D matrix representing an image.
	 *	Rotate the image by 90 degrees (clockwise).
	 *
	 * Note:
	 *	You have to rotate the image in-place, which means you have to
	 *	modify the input 2D matrix directly. DO NOT allocate another 2D
	 *	matrix and do the rotation.
	 *
	 * Example:
	 *	Input: [[1,2,3], [4,5,6], [7,8,9]]
	 *	Output: [[7,4,1], [8,5,2], [9,6,3]]
	 *	
	 *	Input: [[ 5, 1, 9,11], [ 2, 4, 8,10],
	 *		[13, 3, 6, 7], [15,14,12,16]]
	 *	Output: [[15,13, 2, 5], [14, 3, 4, 1],
	 *		[12, 6, 8, 9], [16, 7,10,11]]
	 *=====================================================================
	 */
	void rotate(std::vector<std::vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		if (m < 2 || m != n) return ;

		int row = 0;
		for (int i = 0; i < m/2; ++i) {
			helper(matrix, row++, m-2*i);
		}
	}

	void helper(std::vector<std::vector<int>> &mat, int m, int len) {
		std::vector<int> tmp(len, 0);
		for (int i = 0; i < len-1; ++i) {
			tmp[i] = mat[m][m+i];
			mat[m][m+i] = mat[m+len-1-i][m];
			mat[m+len-1-i][m] = mat[m+len-1][m+len-1-i];
			mat[m+len-1][m+len-1-i] = mat[m+i][m+len-1];
			mat[m+i][m+len-1] = tmp[i];
		}
		mat[m][m+len-1] = tmp[0];
	}
};

void printMatrix(std::vector<std::vector<int>> mat) {
	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[i].size(); ++j) {
			std::cout << nums[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main(int argc, const char *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		int m, n;
		ss >> m >> n;
		std::vector<std::vector<int>> nums(m, std::vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				ss >> nums[i][j];
			}
		}
		printMatrix(nums);

		Solution().rotate(nums);
		printMatrix(nums);
	}

	return 0;
}

