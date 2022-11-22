/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* construct(vector<int>& nums) {
        if (nums.size()==0) return nullptr;
        if (nums.size()==1) {
            TreeNode* root=new TreeNode(nums[0]);
            return root;
        }
        int pos=0,maxNum=nums[0];
        for (int i=0;i<nums.size();++i) {
            if (nums[i]>maxNum) {
                maxNum=nums[i];
                pos=i;
            }
        }
        TreeNode* root=new TreeNode(maxNum);
        vector<int> leftNums(nums.begin(),nums.begin()+pos);
        vector<int> rightNums(nums.begin()+pos+1,nums.end());
        root->left=construct(leftNums);
        root->right=construct(rightNums);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums);
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