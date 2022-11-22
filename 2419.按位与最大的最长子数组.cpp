/*
 * @lc app=leetcode.cn id=2419 lang=cpp
 *
 * [2419] 按位与最大的最长子数组
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
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxNum=INT_MIN;
        for (int i=0;i<n;++i) maxNum=nums[i]>maxNum?nums[i]:maxNum;
        int maxLen=0;
        int len=0;
        if (nums[0]==maxNum) len=1;
        for (int i=1;i<n;++i) {
            if (nums[i]==maxNum) {
                ++len;
                maxLen=max(len,maxLen);
            } else len=0;
        }
        return maxLen;
    }
};
// @lc code=end

