/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

// @lc code=start
class Solution {
public:
    string truncateSentence(string s, int k) {
        string se="";
        string words="";
        int j=0;
        for(int i=0;i<s.size()&&j<k;++i) {
            if(s[i]==' ') {
                se+=words;
                ++j;
                if(j<k) se+=" ";
                words="";
            }else if(i==s.size()-1) {
                words+=s[i];
                se+=words;
                return se;
            }else words+=s[i];
        }
        return se;
    }
};
// @lc code=end

