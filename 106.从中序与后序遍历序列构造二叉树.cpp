/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size()==0) return nullptr;
        TreeNode* root=new TreeNode(postorder[postorder.size()-1]);
        postorder.pop_back();
        if (postorder.size()==0) return root;
        int mid=0;
        for (int i=0;i<inorder.size();++i) {
            if (root->val==inorder[i]) {
                mid=i;
                break;
            }
        }
        vector<int> lInorder(inorder.begin(),inorder.begin()+mid);
        vector<int> rInorder(inorder.begin()+mid+1,inorder.end());

        vector<int> lPostorder(postorder.begin(),postorder.begin()+lInorder.size());
        vector<int> rPostorder(postorder.begin()+lInorder.size(),postorder.end());
        
        root->right=construct(rInorder,rPostorder);
        root->left=construct(lInorder,lPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return construct(inorder,postorder);
    }
};
// @lc code=end

