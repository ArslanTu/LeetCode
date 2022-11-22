/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include <algorithm>
using std::max;
using std::abs;
class Solution {
private:
    bool flag=true;
    int dfs(TreeNode* root) {
        if (root==nullptr) return 0;
        int leftDepth=dfs(root->left);
        int rightDepth=dfs(root->right);
        if (abs(leftDepth-rightDepth)>1) flag=false;
        return max(leftDepth,rightDepth)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;
        dfs(root);
        //return abs(dfs(root->left)-dfs(root->right))<=1;
        return flag;
    }
};
// @lc code=end

