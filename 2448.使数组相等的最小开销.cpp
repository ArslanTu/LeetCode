/*
 * @lc app=leetcode.cn id=2448 lang=cpp
 *
 * [2448] 使数组相等的最小开销
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
using namespace std;
class Solution {
public:
    long long sumCost(const vector<int>& nums, const vector<int>& cost, int mid) {
        const int n = nums.size();
        long long ans = 0;
        for (int i = 0;i < n;++i)
            ans += 1ll * cost[i] * abs(nums[i] - mid);
        return ans;
    }
    
    long long minCost(const vector<int>& nums, const vector<int>& cost) {
        const auto [minit, maxit] = minmax_element(nums.begin(), nums.end());
        long long lo = *minit, hi = *maxit;
        while (lo < hi) {
            const int mi = (lo + hi) / 2;
            if (sumCost(nums, cost, mi) > sumCost(nums, cost, mi + 1))
                lo = mi + 1;
            else hi = mi;
        }
        return sumCost(nums, cost, lo);
    }
};
// @lc code=end

