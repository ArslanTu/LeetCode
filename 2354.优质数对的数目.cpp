/*
 * @lc app=leetcode.cn id=2354 lang=cpp
 *
 * [2354] 优质数对的数目
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
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        long ans = 0L;
        for (auto& num : unordered_set<int>(nums.begin(), nums.end())) ++ump[__builtin_popcount(num)];
        for (auto& elem1 : ump) {
            for (auto& elem2 : ump) {
                if (elem1.first + elem2.first >= k) ans += elem1.second * elem2.second;
            }
        }
        return ans;
    }
};
// @lc code=end

