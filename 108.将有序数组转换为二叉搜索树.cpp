/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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

using std::vector;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
private:
    TreeNode* dfs(const vector<int>& nums,int low,int high) {
        if (low>high) return nullptr;
        int mid=(low+high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=dfs(nums,low,mid-1);
        root->right=dfs(nums,mid+1,high);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
};
// @lc code=end

