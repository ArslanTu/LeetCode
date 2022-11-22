/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <stack>
using std::vector;
using std::stack;
class Solution {
public:
    // vector<int> res;
    // vector<int> inorderTraversal(TreeNode* root) {
    //     tra(root);
    //     return res;
    // }
    // void tra(TreeNode* root){
    //     if(root==nullptr) return;
    //     tra(root->left);
    //     res.insert(res.end(),root->val);
    //     tra(root->right);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while (cur!=nullptr||!st.empty()) {
            if (cur!=nullptr) {
                st.push(cur);
                cur=cur->left;
            } else {
                cur=st.top();
                st.pop();
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ans;
    }

};
// @lc code=end

