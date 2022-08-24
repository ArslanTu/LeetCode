/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
#include <math.h>

using std::min;
using std::vector;
using std::string;
using std::to_string;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        int num=strs.size();
        if(num==1) return strs[0];
        //计算数组中最短字符串的长度
        //前缀必定不超过此长度
        int maxLen=strs[0].size();
        for(int i=1;i<num;++i){
            int strLen=strs[i].size();
            maxLen=(maxLen<strLen)?maxLen:strLen;
        }
        if(maxLen==0) return prefix;
        //以首字符串为准
        //依次对比其各位字符是否与后续串相应位置一致
        //一旦有不一致则返回prefix，结束程序
        //都一致则将该字符加入prefix
        bool flag = true;
        for(int pos=0;flag&&(pos < maxLen);++pos){
            for(int j=1;j<num;++j){
                if(strs[0][pos]!=strs[j][pos]){
                    flag=false;
                    break;
                }
            }
            if(flag) prefix+=strs[0][pos];
        }
        return prefix;
    }
};
// @lc code=end

