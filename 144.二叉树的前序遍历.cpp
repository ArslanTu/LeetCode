/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

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
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        pt(root);
        return res;
    }
    void pt(TreeNode* root){
        if(root==nullptr) return;
        res.push_back(root->val);
        pt(root->left);
        pt(root->right);
    }
};
// @lc code=end

