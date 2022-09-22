/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
public:
    string toLowerCase(string s) {
        string t="";
        for(char &c:s)
        {
            if((int)c>=65&&(int)c<=90) t+=(char)((int)c+32);
            else t+=c;
        }
        return t;
    }
};
// @lc code=end

