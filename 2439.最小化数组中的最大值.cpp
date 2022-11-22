/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 *
 * [2439] 最小化数组中的最大值
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
using namespace std;
class Solution {
private:
    static bool check(vector<int>& nums,int k) {
        long long have=0;
        for (auto num:nums) {
            if (num<=k) have+=k-num;
            else have-=num-k;
            if (have<0) return 0;
        }
        return 1;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left<right) {
            int mid = left+(right-left)/2;
            if (check(nums,mid)) right=mid;
            else left=mid+1;
        }
        return left; //左右皆可，两者最终是相等的
    }
};
// @lc code=end

