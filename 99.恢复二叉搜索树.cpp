/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode* pre;
    TreeNode* pro1;
    TreeNode* pro2;
    TreeNode* pro12;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (pre && pre->val > root->val) {
            if (!pro1) {
                pro1 = pre;
                pro12 = root;
            }
            else if (!pro2) pro2 = root;
            // pre->val ^= root->val;
            // root->val ^= pre->val;
            // pre->val ^= root->val;
        }
        pre=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        pre = nullptr;
        pro1 = nullptr;
        pro2 = nullptr;
        inorder(root);
        if (pro1 && pro2) {
            pro1->val ^= pro2->val;
            pro2->val ^= pro1->val;
            pro1->val ^= pro2->val;
        } else {
            pro1->val ^= pro12->val;
            pro12->val ^= pro1->val;
            pro1->val ^= pro12->val;
        }
        return;
    }
};
// @lc code=end

