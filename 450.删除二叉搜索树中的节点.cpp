/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
private:
    TreeNode* insert(TreeNode* root,TreeNode* child) {
        if (!root) return child;
        if (root->val<child->val) root->right=insert(root->right,child);
        else root->left=insert(root->left,child); 
        return root;
    }
    TreeNode* delNode(TreeNode* root, int& key) {
        if (!root) return root;
        if (root->val==key) {
            if (!root->left&&!root->right) return nullptr;
            else if (!root->left&&root->right) return root->right;
            else if (root->left&&!root->right) return root->left;
            else {
                root->right=insert(root->right,root->left);
                return root->right;
            }
        } else if (root->val<key) {
            root->right=delNode(root->right,key);
        } else {
            root->left=delNode(root->left,key);
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return delNode(root,key);
    }
};
// @lc code=end

