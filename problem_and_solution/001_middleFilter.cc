#include <iostream>
#include <vector>
#include <string>

#define H 512
#define W 512
int img_src[H][W];
int img_dst[H][W];

class Solution {
public:
	Solution();
	~Solution();

	// 冒泡排序法
	void BubbleSort(std::vector<int> &arr);

	// 单通道图像的中值滤波函数，需要包含边界处理，复制边缘，采用冒泡法排序
	void middleFilter(
		std::vector<std::vector<int>> &src,
		std::vector<std::vector<int>> &dst);

public:
	std::vector<std::vector<int>> src;
	std::vector<std::vector<int>> dst;
	std::vector<std::pair<int,int>> shift{
		   {-1,-1},{-1,0},{-1,1},
		   {0,-1},{0,0},{0,1},
		   {1,-1},{1,0},{1,1}};
};

void Solution::BubbleSort(std::vector<int> &arr) {
	int len = arr.size();
	if (len <= 0)
		return;
	
	bool needNextTraverse = true;
	for (int i = 0; i < len && needNextTraverse; i++) {
		needNextTraverse = false;
		for (int j = 0; j < len - i; j++) {
			if (arr[j] > arr[j+1]) {
				int tmp = arr[j];
				arr[i] = arr[j+1];
				arr[j+1] = tmp;
				needNextTraverse = true;
			}
		}
	}
}

void Solution::middleFilter(std::vector<std::vector<int>> &src,
	std::vector<std::vector<int>> &dst) {
	int height = src.size();
	int width = src[0].size();

	for (int x = 0; x < height; x++) {
	   for (int y = 0; y < width; y++) {
	       std::vector<int> tmp;
	       for (int k = 0; k < 9; k++){
	           int x_tmp = x + shift[k].first;
	           int y_tmp = y + shift[k].second;
	           x_tmp = ((x_tmp < 0) ? 0 : ((x_tmp >= height) ? (height-1) : x_tmp));
	           y_tmp = ((y_tmp < 0) ? 0 : ((y_tmp >= width) ? (width-1) : y_tmp));
	           tmp.push_back(src[x_tmp][y_tmp]);
	       }
	       BubbleSort(tmp);
	       dst[x][y] = tmp[4];
	   }
	}
}

int main (int argc, char **argv)
{
	if (argc > 0) {
		for(int i = 0; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;
	}
	Solution solver;
	solver.src.assign(img_src, img_src+H*W);
	solver.dst.assign(img_dst, img_dst+H*W);
	solver.middleFilter(solver.src, solver.dst);

	return 0;
}
