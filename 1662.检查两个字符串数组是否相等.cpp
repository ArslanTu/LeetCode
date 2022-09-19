/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s="",t="";
        for(string c:word1) s+=c;
        for(string c:word2) t+=c;
        return s==t;
    }
};
// @lc code=end

