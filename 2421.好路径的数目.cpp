/*
 * @lc app=leetcode.cn id=2421 lang=cpp
 *
 * [2421] 好路径的数目
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
class MyNode {
public:
    int val;
    MyNode* left;
    MyNode* right;
    MyNode(int x) {
        val=x;
        left=nullptr;
        right=nullptr;
    }
    MyNode() {
        val=0;
        left=nullptr;
        right=nullptr;
    }
};
class Solution {
private:
    int ans=0;
    void dfs(int start,MyNode* root) {
        if (root==nullptr||root->val>start) return;
        if (root->val==start) ++ans;
        if (root->left!=nullptr) dfs(start,root->left); 
        if (root->right!=nullptr) dfs(start,root->right);
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        int m=edges.size();
        ans=n;
        vector<MyNode*> tree(n);
        for (int i=0;i<n;++i) {
            MyNode* root=new MyNode(vals[i]);
            tree[i]=root;
        }
        for (int i=0;i<m;++i) {
            if (tree[edges[i][0]]->left==nullptr) tree[edges[i][0]]->left=tree[edges[i][1]];
            else tree[edges[i][0]]->right=tree[edges[i][1]];
        }
        for (int i=0;i<n;++i) dfs(tree[i]->val,tree[i]);
        return ans;

    }
};
// @lc code=end

