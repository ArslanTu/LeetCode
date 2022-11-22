/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
// private:
//     vector<vector<int>> res;
// public:
//     vector<vector<int>> combine(int n, int k) {
//         for (int i=1;i<=n-k+1;++i) {
//             vector<int> v;
//             backtracking(v,i,k,0,n);
//         }
//         return res;
//     }
//     void backtracking(vector<int> v,int next,int k,int deep,int n) {
//         v.push_back(next);
//         ++deep;
//         if (deep==k) {
//             res.push_back(v);
//             return;
//         }
//         for (int i=next+1;i<=n;++i) {
//             backtracking(v,i,k,deep,n);
//         }
//     }
private:
    vector<vector<int>> res;
    vector<int> v;
    void backtracking(int k,int start,int n) {
        if (v.size()==k) {
            res.push_back(v);
            return;
        }
        for (int i=start;i<=n-(k-v.size())+1;++i) {
            v.push_back(i);
            backtracking(k,i+1,n);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        v.clear();
        backtracking(k,1,n);
        return res;
    }
};
// @lc code=end

