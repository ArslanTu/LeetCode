/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <string>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0,p1=a.size()-1,p2=b.size()-1;
        string c="";
        while(carry!=0||p1>=0||p2>=0){
            int val_1=(p1>=0)?(int(a[p1])-48):0;
            int val_2=(p2>=0)?(int(b[p2])-48):0;
            int sum=carry+val_1+val_2;
            c.insert(c.begin(),char(sum%2+48));
            carry=sum/2;
            if(p1>=0) p1-=1;
            if(p2>=0) p2-=1;
        }
        return c;
    }
};
// @lc code=end