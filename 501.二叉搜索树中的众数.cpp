/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
// private:
//     map<int,int> mp;
//     void dfs(TreeNode* root) {
//         if (!root) return;
//         mp[root->val]++;
//         dfs(root->left);
//         dfs(root->right);
//     }
// public:
//     vector<int> findMode(TreeNode* root) {
//         mp.clear();
//         int maxFreq=INT_MIN;
//         dfs(root);
//         for (auto& elem:mp) maxFreq=max(maxFreq,elem.second);
//         vector<int> ans;
//         for (auto& elem:mp) if (elem.second==maxFreq) ans.push_back(elem.first);
//         return ans;
//     }
private:
    TreeNode* pre;
    vector<int> ans;
    int cnt=0;
    int maxCnt=0;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);

        if (!pre) {
            cnt=1;
            maxCnt=1;
            ans.push_back(root->val);
        } else {
            if (root->val==pre->val) {
                ++cnt;
                if (cnt>maxCnt) {
                    ans.clear();
                    maxCnt=cnt;
                }
            } else cnt=1;
            if (cnt==maxCnt) ans.push_back(root->val);
        }
        pre=root;

        dfs(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        ans.clear();
        pre=nullptr;
        cnt=0;
        maxCnt=0;
        dfs(root);
        return ans;
    }
};
// @lc code=end

