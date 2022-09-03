/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <string>

using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        //字符串做法
        string t="";
        string u="";
        for(auto e:s){
            if(int(e)>=65&&int(e)<=90){
                t.insert(t.begin(),(char)((int)e+32));
                u+=(char)((int)e+32);
            }
            else if((int(e)>=97&&int(e)<=122)||(int(e)>=48&&int(e)<=57)){
                t.insert(t.begin(),e);
                u+=e;
            }
        }
        return u==t;
    }
};
// @lc code=end

