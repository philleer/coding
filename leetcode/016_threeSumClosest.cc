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
#include <vector>
#include <sstream>
#include <cmath>

class Solution {
public:
        // 16. 3Sum Closest
        /*=====================================================================
         * Description: Given an array nums of n integers and an integer target,
         *      find three integers in nums such that the sum is closest to
         *      target. Return the sum of the three integers.
         *      You may assume that each input would have exactly one solution.
         *
         * Example:
         *      Input: nums = [-1, 2, 1, -4], target = 1
         *      Output: 2
         *      Explanation: The sum that is closest to the target is 2.
         *      (-1 + 2 + 1 = 2).
         *=====================================================================
         */
        int threeSumClosest(vector<int>& nums, int target) {
                if (nums.size() <= 3) {
                        int sum = 0;
                        for (int i = 0; i < nums.size(); ++i) {
                                sum += nums[i];
                        }
                        return sum;
                }
                std::sort(nums.begin(), nums.end());

                int res = 0;
                int min_diff = 65536;   // INT_MAX
                for (int i = 0; i < nums.size()-2; ++i) {
                        for (int j = nums.size()-1; j > i+1; --j) {
                                for (int k = i+1; k < j; ++k) {
                                        int sum = nums[i] + nums[j] + nums[k];
                                        if (std::abs(target-sum) < min_diff) {
                                                res = sum;
                                                min_diff = std::abs(target-sum);
                                        }
                                }
                        }
                }

                return res;
        }

        int threeSumClosest(vector<int>& nums, int target) {
                if (nums.size() <= 3) {
                        int sum = 0;
                        for (int i = 0; i < nums.size(); ++i) {
                                sum += nums[i];
                        }
                        return sum;
                }
                std::sort(nums.begin(), nums.end());

                int res = 0;
                int min_diff = 65536;
                for (int i = 0; i < nums.size()-2; ++i) {
                        int low = i+1;
                        int high = nums.size()-1;
                        while (low < high) {
                                int sum = nums[low]+nums[high]+nums[i];
                                if (std::abs(target-sum) < min_diff) {
                                        res = sum;
                                        min_diff = std::abs(target-sum);
                                }
                                if (target < sum) --high;
                                if (target > sum) ++low;
                                if (target == sum) return res;
                        }
                }

                return res;
        }
};

int main (int argc, char *argv[]) {
        std::string line;
        while (std::getline(std::cin, line)) {
                std::stringstream ss;
                ss.str(line);
                int num;
                ss >> num;
                std::vector<int> nums(num, 0);
                for (int i = 0; i < num; ++i) {
                        ss >> nums[i];
                        std::cout << nums[i] << " ";
                }
                std::cout << std::endl;

                int result = 
                std::cout << "The cloest result sum is: "
                        << Solution().threeSumClosest(nums)
                        << std::endl;
        }

        return 0;
}
