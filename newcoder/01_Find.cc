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
#include <vector>

using namespace std;

class Solution
{
public:
	/*=============================================================
	 * 题目描述：在一个二维数组中（每个一维数组长度相同），每一行都按照
	 *			从左到右递增的顺序排序，每一列都按照从上到下递增的顺序
	 *			排序。请完成一个函数，输入这样一个二维数组和一个整数，
	 *			判断数组中是否含有该整数。
	 * 解题思路：逐行逐列扫描太过耗时，寻找题目中数组本身的性质，从左向
	 *			右，从上到下递增，因此可以以左下或右上为搜索起点，比目
	 *			标值大则向左搜索，比目标值小则向下搜索，直到搜索完毕。
	 *=============================================================
	 */
	bool Find(int target, vector<vector<int> > array) {
		int numRows = array.size();
		// 考虑特殊情况下的特殊输出，数据为空返回搜索不到目标值
		if (numRows == 0)
			return false;

		for (int curRow = 0; curRow < numRows; curRow++) {
			for (int curColumn = array[curRow].size() - 1;
				curColumn >= 0; curColumn--) {
				int temp = array[curRow][curColumn];
				if (target == temp)
					return true;
				else
					if (target < temp)
						continue;
					else
						break;
			}
		}

		return false;
	}
};

int main()
{
	// 测试案例
	int a[4][4] = {{1,2,8,9},{2,4,8,9},{4,7,10,13},{6,8,11,15}};
	vector<vector<int> > vectorTest;

	for (int i = 0; i < 4; i++) {
		// vector为空时无法访问vector[0]，所以此处定义了中间变量
		vector<int> temp;
		for (int j = 0; j < 4; j++) {
			temp.push_back(a[i][j]);
		}
		vectorTest.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << vectorTest[i][j] << " ";
		cout << endl;
	}
	int target;
	cin >> target;

	Solution solver;
	// C++中cout输出时会将true视为1，false视为0
	cout << target << " in the array?\n"
		<< (solver.Find(target <<,vectorTest)?"true":"false")
		<< endl;

	return 0;
}