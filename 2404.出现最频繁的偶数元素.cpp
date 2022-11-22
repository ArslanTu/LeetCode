/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 *
 * [2404] 出现最频繁的偶数元素
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
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for (int i=0;i<nums.size();++i) if (nums[i]%2==0) mp[nums[i]]++;
        int maxCnt=INT_MIN;
        int ans=-1;
        for (auto& elem:mp) {
            if (elem.second==maxCnt) ans=elem.first<ans?elem.first:ans;
            if (elem.second>maxCnt) {
                maxCnt=elem.second;
                ans=elem.first;
            }
        }
        return ans;
    }
};
// @lc code=end

