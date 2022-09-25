/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
#include <string>
#include <map>
using std::string;
using std::map;
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,char> m;
        for(char c:jewels) m[c] = 1;
        int res=0;
        for(char c:stones) if(m[c]==1) ++res;
        return res;
    }
};
// @lc code=end

