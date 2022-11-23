/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
//     void inorder(TreeNode* root,vector<TreeNode*>& tree) {
//         if (!root) return;
//         inorder(root->left,tree);
//         tree.push_back(root);
//         inorder(root->right,tree);
//     }
// public:
//     TreeNode* convertBST(TreeNode* root) {
//         vector<TreeNode*> tree;
//         inorder(root,tree);
//         for (int i=tree.size()-2;i>=0;--i) tree[i]->val+=tree[i+1]->val;
//         return root;
//     }
private:
    TreeNode* pre;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->right);
        root->val+=pre->val;
        pre=root;
        inorder(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        pre=new TreeNode(0);
        inorder(root);
        return root;
    }
};
// @lc code=end

