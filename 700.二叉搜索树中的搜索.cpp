/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
class Solution {
private:
    void inorder(TreeNode* root,vector<TreeNode*>& tree) {
        if (root==nullptr) return;
        inorder(root->left,tree);
        tree.push_back(root);
        inorder(root->right,tree);
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<TreeNode*> tree;
        inorder(root,tree);
        int left=0,right=tree.size()-1;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if (tree[mid]->val==val) return tree[mid];
            else if (tree[mid]->val<val) left=mid+1;
            else right=mid-1;
        }
        return nullptr;
    }
};
// @lc code=end

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