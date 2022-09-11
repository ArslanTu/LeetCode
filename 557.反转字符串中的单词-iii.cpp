/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
#include <string>
using std::string;

class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==1) return s;
        string t="";
        string word="";
        int i=0;
        for(;i<s.length();++i){
            if(s[i]==' '){
                t+=word + " ";
                word="";
            }else word.insert(word.begin(),s[i]);
        }
        return t+word;
    }
};
// @lc code=end

