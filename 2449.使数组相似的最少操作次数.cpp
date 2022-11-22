/*
 * @lc app=leetcode.cn id=2449 lang=cpp
 *
 * [2449] 使数组相似的最少操作次数
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
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> oddNums;
        vector<int> pairNums;
        vector<int> oddTarget;
        vector<int> pairTarget;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        for (auto elem:nums) {
            if (elem%2==1) oddNums.push_back(elem);
            else pairNums.push_back(elem);
        }
        
        for (auto elem:target) {
            if (elem%2==1) oddTarget.push_back(elem);
            else pairTarget.push_back(elem);
        }

        long long oddOps=0,pairOps=0;
        int m=oddNums.size();
        int n=pairNums.size();
        for (int i=0;i<m;++i) {
            oddOps+=abs(oddNums[i]-oddTarget[i])/2;
        }
        for (int i=0;i<n;++i) {
            pairOps+=abs(pairNums[i]-pairTarget[i])/2;
        }
        return (oddOps+pairOps)/2;
    }
};
// @lc code=end

