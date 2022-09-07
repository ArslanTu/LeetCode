/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        while(columnNumber!=0){
            int num = columnNumber%26==0?26:columnNumber%26;
            s+=char(num+64);
            columnNumber = (columnNumber-num)/26;
        }
        string res(s.rbegin(),s.rend());
        return res;
    }
};
// @lc code=end

