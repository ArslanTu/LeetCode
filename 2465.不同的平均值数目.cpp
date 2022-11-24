/*
 * @lc app=leetcode.cn id=2465 lang=cpp
 *
 * [2465] 不同的平均值数目
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
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        map<double,int> mp;
        sort(nums.begin(),nums.end());
        int ans=0;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            if (mp[double(nums[i]+nums[j])/2.0]!=1) {
                mp[double(nums[i]+nums[j])/2.0]=1;
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

