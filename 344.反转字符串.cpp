/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()>>1;++i){
            char temp = s[i];
            s[i]=s[s.size()-1-i];
            s[s.size()-1-i]=temp;
        }
    }
};
// @lc code=end

