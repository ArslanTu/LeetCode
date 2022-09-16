/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
#include <map>
using std::map;
class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> m;
        for(auto &c:s) m[c]+=1;
        for(auto &c:t) {
            if(m[c]>=1) --m[c];
            else return c;
        }
        return 'q';
    }
};
// @lc code=end

