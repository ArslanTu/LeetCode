/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* construct(vector<int>& preorder, vector<int>& inoreder) {
        if (inoreder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        
        int i = 0;
        for (; i < inoreder.size(); ++i) {
            if (inoreder[i] == root->val) break;
        }

        vector<int> leftIn(inoreder.begin(), inoreder.begin() + i);
        vector<int> rightIn(inoreder.begin() + i + 1, inoreder.end());

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + leftIn.size() + 1);
        vector<int> rightPre(preorder.begin() + leftIn.size() + 1, preorder.end());

        root->left = construct(leftPre, leftIn);
        root->right = construct(rightPre, rightIn);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(preorder, inorder);
    }
};
// @lc code=end

