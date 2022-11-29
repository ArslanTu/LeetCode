/*
 * @lc app=leetcode.cn id=2344 lang=cpp
 *
 * [2344] 使数组可以被整除的最少删除次数
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
private:
    int gcd (int a, int b) {
        if (a < b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        if (b == 0) return a;
        else return gcd(b, a % b);
    }
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int maxFac = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); ++i) maxFac = gcd(maxFac, numsDivide[i]);
        sort(nums.begin(), nums.end());
        int j = 0;
        int ans = 0;
        for (; j < nums.size(); ++j) {
            if (maxFac % nums[j] == 0) break;
            else ++ans;
        }
        return ans == nums.size() ? -1 : ans;
    }
};
// @lc code=end

