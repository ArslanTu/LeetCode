/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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

#include <vector>
using std::vector;
using std::max;
class Solution {
public:
    int rob(TreeNode* root) {
        return max(robTree(root)[0],robTree(root)[1]);
    }

    vector<int> robTree(TreeNode* cur) {
        if (cur==nullptr) return vector<int>{0,0};
        vector<int> left=robTree(cur->left);
        vector<int> right=robTree(cur->right);
        int val1=max(left[0],left[1])+max(right[0],right[1]);
        int val2=left[0]+right[0]+cur->val;
        return vector<int>{val1,val2};
    }

};
// @lc code=end

