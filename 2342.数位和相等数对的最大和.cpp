/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        auto bitSum = [&](int num) -> int {
            int x = num;
            int sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };

        int n = nums.size();
        unordered_map<int, vector<int>> ump;
        vector<int> bitSums(n);
        for (int i = 0; i < n; ++i) {
            bitSums[i] = bitSum(nums[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            ump[bitSums[i]].push_back(nums[i]);
        }
        for (auto& elem : ump) {
            int m = elem.second.size();
            if (m == 1) continue;
            sort(elem.second.begin(),elem.second.end());
            ans = max(ans, elem.second[m - 1] + elem.second[m - 2]);
        }
        return ans;
    }
};
// @lc code=end

