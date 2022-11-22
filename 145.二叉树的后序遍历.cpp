/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <stack>
using std::vector;
using std::stack;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };


class Solution {
public:
    // vector<int> res;
    // vector<int> postorderTraversal(TreeNode* root) {
    //     afs(root);
    //     return res;
    // }
    // void afs(TreeNode* root){
    //     if(root==nullptr) return;
    //     afs(root->left);
    //     afs(root->right);
    //     res.insert(res.end(),root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root==nullptr) return ans;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        st.push(cur);
        while(!st.empty()) {
            cur=st.top();
            st.pop();
            ans.push_back(cur->val);
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        return vector<int>(ans.rbegin(),ans.rend());
    }
};
// @lc code=end

