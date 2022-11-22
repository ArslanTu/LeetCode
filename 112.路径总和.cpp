/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
private:
    int path;
    bool flag=false;
    void backtracking(int targetSum,TreeNode* root) {
        if (root->left==nullptr&&root->right==nullptr) {
            if (path==targetSum) flag=true;
            return;
        }
        if (root->left!=nullptr) {
            path+=root->left->val;
            backtracking(targetSum,root->left);
            path-=root->left->val;
        }
        if (root->right!=nullptr) {
            path+=root->right->val;
            backtracking(targetSum,root->right);
            path-=root->right->val;
        }        
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr) return false;
        path=root->val;
        flag=false;
        backtracking(targetSum,root);
        return flag;
    }
};
// @lc code=end

