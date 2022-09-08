/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <map>
#include <string>
using std::map;
using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m,n;
        for(auto &iter:s) ++m[iter];
        for(auto &iter:t) ++n[iter];
        return m==n;
    }
};
// @lc code=end

