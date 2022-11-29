/*
 * @lc app=leetcode.cn id=2341 lang=cpp
 *
 * [2341] 数组能形成多少数对
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
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> ans(2, 0);
        // unordered_map<int, int> ump;
        // for (auto& num : nums) {
        //     ump[num]++;
        //     if (ump[num] == 2) {
        //         ump.erase(num);
        //         ++ans[0];
        //     }
        // }
        // ans[1] = ump.size();
        vector<int> cnt(101, 0);
        for (auto& num : nums) {
            ++cnt[num];
            if ((cnt[num] & 1) == 0) ++ans[0];
        }
        ans[1] = nums.size() - (ans[0] << 1);
        return ans;
    }
};
// @lc code=end

