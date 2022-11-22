/*
 * @lc app=leetcode.cn id=2442 lang=cpp
 *
 * [2442] 反转之后不同整数的数目
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
private:
    int revert(const int& x) {
        vector<short> pos;
        int y=x;
        while (y!=0) {
            pos.push_back(y%10);
            y/=10;
        }
        for (int i=0;i<pos.size();++i) y+=pos[i]*pow(10,pos.size()-i-1);
        return y;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;++i) nums.push_back(revert(nums[i]));
        sort(nums.begin(),nums.end());
        int ans=1;
        for (int i=1;i<nums.size();++i) if (nums[i]!=nums[i-1]) ++ans;
        return ans;
    }
};
// @lc code=end

