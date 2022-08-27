/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <string>
#include <sstream>

using std::string;
using std::getline;
using std::stringstream;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        string last;
        while(getline(ss,word,' ')){
            if(!word.empty()) last=word;
        }
        return last.size();
    }
};
// @lc code=end

