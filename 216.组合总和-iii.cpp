/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> v;
    int sum=0;
    void backtracking(int start,int k,int n) {
        if (sum>n) return;
        if (v.size()==k) {
            if (sum==n) res.push_back(v);
            return;
        }
        for (int i=start;i<=9-(k-v.size())+1;++i) {
            v.push_back(i);
            sum+=i;
            backtracking(i+1,k,n);
            v.pop_back();
            sum-=i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        v.clear();
        sum=0;
        backtracking(1,k,n);
        return res;
    }
};
// @lc code=end

