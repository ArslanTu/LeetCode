/*
 * @lc app=leetcode.cn id=2454 lang=cpp
 *
 * [2454] 下一个更大元素 IV
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
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        if (n==1) return vector<int>{-1};
        if (n==2) return vector<int> {-1,-1};
        for (int i=0;i<n-2;++i) {
            // 这个判断语句用于剪枝
            if (i>0&&((nums[i]==nums[i-1])||nums[i]-nums[i-1]==-1)) {
                ans.push_back(ans[i-1]);
                continue;
            }
            bool flag=false;
            int sign=-1;
            for (int j=i+1;j<n;++j) {
                if (nums[j]>nums[i]) {
                    if (flag==false) {
                        flag=true;
                        continue;
                    } else {
                        sign=nums[j];
                        break;
                    }
                }
            }
            ans.push_back(sign);
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};
// @lc code=end

