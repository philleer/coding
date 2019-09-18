#include <cstdio>
#include <vector>
#include <cmath>
#include <float.h>	// FLT_MAX 3.402823466e+38F
#include <stdexcept>	// std::invalid_argument
#include <limits>	// std::numeric_limits

#define PI 3.141593

class Solution {
public:
	Solution(){}
	~Solution() {}
	std::vector<std::vector<float>> &gaussian_kernel(int size, float sigma);
	float fpow(float x);
};

std::vector<std::vector<float>> &Solution::gaussian_kernel(int size, float sigma) {
	std::vector<std::vector<float>> result;
	if (size <= 0 || sigma < 1e-5) {
		return result;
	}

	int bound = size / 2;
	float sum = 0.0f;
	for (int y = 0; y < size; y++) {
		std::vector<float> vec_tmp;
		for (int x = 0; x < size; x++) {
			float value_tmp = exp(-(fpow(x - bound) + fpow(y - bound))) / (2 * PI * sigma * sigma);
			vec_tmp.push_back(value_tmp);
			sum += value_tmp;
		}
		result.push_back(vec_tmp);
	}

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			result[y][x] /= sum;
		}
	}

	return result;
}

float Solution::fpow(float x) {
	float res = x * x;
	if (res >= FLT_MAX) {
		// float floatMax = std::numeric_limits<float>::max();
		throw std::invalid_argument("Overflow the float range!");
		return FLT_MAX;
	}
	
	return res;
}

int main(int argc, char *argv[]) {
	int size;
	float sigma;
	scanf("%d %f", &size, &sigma);

	std::vector<std::vector<float>> kernel;
	Solution solver;
	kernel = solver.gaussian_kernel(size, sigma);
	for (auto vec : kernel) {
		for (auto ele : *vec) {
			printf("%f ", *ele);
		}
		printf("\n");
	}


	return 0;
}