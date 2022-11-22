/*
 * @lc app=leetcode.cn id=2453 lang=cpp
 *
 * [2453] 摧毁一系列目标
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
    int destroyTargets(vector<int>& nums, int space) {
        vector<int> nums_copy=nums;
        for (int i=0;i<nums_copy.size();++i) nums_copy[i]=nums_copy[i]%space;
        map<int,int> mp;
        for (auto num:nums_copy) ++mp[num];
        int king=nums_copy[0];
        map<int,int> kings;
        for (auto elem:mp) king=elem.second>mp[king]?elem.first:king;
        for (auto elem:mp) if (elem.second==mp[king]) kings[elem.first]=1;
        vector<int> record;
        for (int i=0;i<nums_copy.size();++i) {
            if (kings[nums_copy[i]]==1) record.push_back(nums[i]);
        }
        int ans=INT_MAX;
        for (auto elem:record) ans=elem<ans?elem:ans;
        return ans;
    }
};
// @lc code=end

