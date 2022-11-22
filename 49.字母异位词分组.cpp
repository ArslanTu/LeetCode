/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using std::vector;
using std::string;
using std::map;
using std::sort;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.size()<=1) {
            res.push_back(strs);
            return res;
        }
        
        map<string,vector<string>> fa;

        for (int i=0;i<strs.size();++i) {
            string elem_sorted = strs[i];
            sort(elem_sorted.begin(),elem_sorted.end());
            fa[elem_sorted].push_back(strs[i]);
        }
        for (auto e:fa) res.push_back(e.second);
        return res;

    }
};
// @lc code=end

