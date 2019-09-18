#include <cstdio>
#include <vector>
#include <cmath>
#include <float.h>		// FLT_MAX 3.402823466e+38F
#include <stdexcept>	// std::invalid_argument
#include <limits>		// std::numeric_limits

// #define PI 3.141593

class Solution {
public:
	Solution(){}
	~Solution() {}
	void gaussian_kernel(int size, float sigma, std::vector<std::vector<float>> &res);
	float fpow(float x);
};

void Solution::gaussian_kernel(int size, float sigma, std::vector<std::vector<float>> &res) {
	if (size <= 0 || sigma < 1e-5) {
		throw std::invalid_argument("Invalid size or sigma!");
	}

	int bound = size / 2;
	float sum = 0.0f;
	// f(x, y) = 1 / (2*pi*sigma) * exp(-(x*x+y*y)/(2*sigma*sigma))
	// when normalize it is no need for the factor 1/(2*pi*sigma)
	for (int y = 0; y < size; y++) {
		std::vector<float> vec_tmp;
		for (int x = 0; x < size; x++) {
			float value_tmp = exp(-(fpow(x - bound) + fpow(y - bound)))
				   /* / (2 * PI * sigma * sigma) */;
			vec_tmp.push_back(value_tmp);
			sum += value_tmp;
		}
		res.push_back(vec_tmp);
	}

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			res[y][x] /= sum;
		}
	}
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
	Solution().gaussian_kernel(size, sigma, kernel);
		
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			printf("%f ", kernel[y][x]);
		}
		printf("\n");
	}

	return 0;
}

