/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <map>
#include <string>
using std::string;
using std::map;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m,n;
        for(int i=0;i<s.length();++i){
            m[s[i]]=t[i];
            n[t[i]]=s[i];
        }
        string s2="",t2="";
        for(int j=0;j<s.length();++j){
            s2+=m[s[j]];
            t2+=n[t[j]];
        }
        return t==s2&&s==t2;
    }
};
// @lc code=end

