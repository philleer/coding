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
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>

class Solution {
public:
        // 169. Majority Element
        /*====================================================================
         * Description: Given an array of size n, find the majority element.
         *      The majority element is the element that appears more than n/2
         *      times.
         * Note:
         *      You may assume that the array is non-empty and the majority
         *      element always exist in the array.
         *
         * Example:
         *      Input: [3,2,3]  Output: 3
         *      Input: [2,2,1,1,1,2,2]  Output: 2
         *====================================================================
         */
        int majorityElement(vector<int>& nums) {
                if (nums.empty()) return 0;
                int size = nums.size();
                std::unordered_map<int, int> mp;

                int res = nums[0];
                int max = 0;
                for (int i = 0; i < size; ++i) {
                        if (mp.find(nums[i]) == mp.end()) {
                                mp.insert(std::make_pair<int, int>(
                                          (int)nums[i], 1)
                                         );
                        } else {
                                mp[nums[i]] += 1;
                                if (mp[nums[i]] > max) {
                                        max = mp[nums[i]];
                                        res = nums[i];
                                }
                        }
                }

                return res;
        }
};

int main(int argc, char *argv[]) {
        std::string line;
        while (std::getline(std::cin, line)) {
                int num;
                std::stringstream ss;
                ss.str(line);
                ss >> num;
                std::vector<int> nums(num, 0);
                for (int i = 0; i < num; ++i) {
                        ss >> nums[i];
                        std::cout << nums[i] << " ";
                }
                std::cout << std::endl;

                int ret = Solution().majorityElement(nums);
                std::cout << "The majority element of the given vector is:"
                        << ret << std::endl;
        }
        return 0;
}
