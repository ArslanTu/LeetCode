/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
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
private:
    void dfs(int& ans,TreeNode* root,bool flag) {
        if (root->left==nullptr&&root->right==nullptr&&flag) {
            ans+=root->val;
            return;
        } else if (root->left==nullptr&&root->right==nullptr&&!flag) {
            return;
        }
        if (root->left!=nullptr) dfs(ans,root->left,true);
        if (root->right!=nullptr) dfs(ans,root->right,false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        dfs(ans,root,false);
        return ans;
    }
};
// @lc code=end

