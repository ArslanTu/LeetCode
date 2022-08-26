/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start

/*
热评说得好。
你要想考KMP，干嘛标个Easy？
要是用内置函数，那这题意义何在？
*/
#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        auto result = haystack.find(needle);
        return result==string::npos?-1:result;
    }
};
// @lc code=end

