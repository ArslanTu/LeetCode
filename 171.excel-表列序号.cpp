/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
#include <string>
#include <math.h>
using std::pow;
using std::string;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum=0;
        for(int i=0;i<columnTitle.length();++i){
            sum += (int(columnTitle[i])-64) * pow(26,columnTitle.length()-1-i);
        }
        return sum;
    }
};
// @lc code=end

