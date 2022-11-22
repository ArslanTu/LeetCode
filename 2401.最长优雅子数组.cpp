/*
 * @lc app=leetcode.cn id=2401 lang=cpp
 *
 * [2401] 最长优雅子数组
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
    int longestNiceSubarray(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        if (n==1) return 1; 
        int sum=0;
        int left=0;
        for (int right=0;right<n;++right) {
            while(sum&nums[right]) sum^=nums[left++];
            sum^=nums[right];
            ans=right-left+1>ans?right-left+1:ans;
        }
        return ans;
    }
};
// @lc code=end

