/*
 * @lc app=leetcode.cn id=2441 lang=cpp
 *
 * [2441] 与对应负数同时存在的最大正整数
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
    int findMaxK(vector<int>& nums) {
        if (nums.size()==1) return -1;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while (nums[i]<0&&nums[j]>0) {
            if (nums[i]==-nums[j]) return nums[j];
            else if (-nums[i]>nums[j]) ++i;
            else --j;
        }
        return -1;
    }
};
// @lc code=end

