#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

#define M 512
#define N 512
int image1[M][N];
int image2[M][N];

class Solution {
public:
	Solution() {}
	~Solution() {}

public:
	bool histCount(
		std::vector<std::vector<int>> &img,
		std::unordered_map<unsigned char, float> &mp);
	float histSimilarity(
		std::vector<std::vector<int>> &img1,
		std::vector<std::vector<int>> &img2);

public:
	std::vector<std::vector<int>> _img1;
	std::vector<std::vector<int>> _img2;
};

bool Solution::histCount(
	std::vector<std::vector<int>> &img,
	std::unordered_map<unsigned char, float> &mp) {
	if (img.size() <= 0)
		return false;

	int pixel_num = img.size() * img[0].size();
	for (int index = 0; index < (1 << sizeof(unsigned char)); index++) {
		mp[index] = 0.0f;
	}

	for (size_t x = 0; x < img.size(); x++) {
		for (size_t y = 0; y < img[0].size(); y++) {
			int tmp = img[x][y];
			if (mp.find(tmp) != mp.end())
				mp[tmp] += 1.0f / static_cast<float>(pixel_num);
		}
	}

	return true;
}

float Solution::histSimilarity(
	std::vector<std::vector<int>> &img1,
	std::vector<std::vector<int>> &img2) {
	if (img1.size() <= 0 || img2.size() <= 0)
		return 0;

	std::unordered_map<unsigned char, float> mp1, mp2;
	float similarity = 0.0f;
	if(histCount(img1, mp1) && histCount(img2, mp2)) {
		// first measurement ==> correlation
		// int valid_bin_num1 = 0;
		// int valid_bin_num2 = 0;
		// for (auto iter1 = mp1.begin(); iter1 != mp1.end(); iter1++) {
		// 	if (iter1->second > 1e-5) {
		// 		++valid_bin_num1;
		// 	}
		// 	auto iter2 = mp2.find(iter1->first);
		//     if (iter2 != mp2.end()) {
		//     	if (iter2->second > 1e-5) {
		//     		++valid_bin_num2;
		//     	}
		//     }
		// }
		// float avg_hist_value1 = 1.0f / static_cast<float>(valid_bin_num1);
		// float avg_hist_value2 = 1.0f / static_cast<float>(valid_bin_num2);

		int pixel_num = img1.size() * img1[0].size();
		float avg_hist_value = 1.0f / static_cast<float>(pixel_num);
		float denominator_first = 0.f, denominator_second = 0.f;
		float numerator = 0.f;
		for (auto iter1 = mp1.begin(); iter1 != mp1.end(); iter1++) {
			auto iter2 = mp2.find(iter1->first);
			if (iter2 != mp2.end()) {
				numerator += (std::fabs(iter1->second - avg_hist_value) *
						std::fabs(iter2->second - avg_hist_value));
				denominator_first += (iter1->second - avg_hist_value) *
						(iter1->second - avg_hist_value);
				denominator_second += (iter2->second - avg_hist_value) *
						(iter2->second - avg_hist_value);
			}
		}
		float denominator = std::sqrt(denominator_first * denominator_second);
		float similarity = numerator / denominator;
		return similarity;

		// second measurement ==> chi-square
		for (auto iter1 = mp1.begin(); iter1 != mp1.end(); iter1++) {
			auto iter2 = mp2.find(iter1->first);
			if (iter2 != mp2.end()) {
				float tmp = (iter1->second - iter2->second) * (iter1->second - iter2->second) /
						(iter1->second + iter2->second);
				similarity += tmp;
			}
		}
		return similarity;

		// third measurement ==> intersection
		for (auto iter1 = mp1.begin(); iter1 != mp1.end(); iter1++) {
			auto iter2 = mp2.find(iter1->first);
			if (iter2 != mp2.end()) {
				float tmp = std::min(iter1->second, iter2->second);
				similarity += tmp;
			}
		}
		return similarity;

		// forth measurement ==> bhattacharyya
		for (auto iter1 = mp1.begin(); iter1 != mp1.end(); iter1++) {
			auto iter2 = mp2.find(iter1->first);
			if (iter2 != mp2.end()) {
				similarity += std::sqrt(iter1->second * iter2->second);
			}
		}
		return std::sqrt(1.0f - similarity);
	}

	return similarity;
}

int main(int argc, char **argv) {
	if (argc > 0) {
		for (int i = 0; i < argc; i++) {
			std::cout << argv[i] << " ";
		}
		std::cout << std::endl;
	}
	
	Solution solver;
	solver._img1.assign(image1, image1+M*N);
	solver._img2.assign(image2, image2+M*N);
	float similar_score = solver.histSimilarity(solver._img1, solver._img2);
	std::cout << "similarity of the two image is " << similar_score << std::endl;

	return 0;
}

