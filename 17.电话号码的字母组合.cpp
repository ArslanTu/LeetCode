/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution {
private:
    const vector<vector<int>> m={{},{},{97,98,99},{100,101,102},{103,104,105},{106,107,108},{109,110,111},{112,113,114,115},{116,117,118},{119,120,121,122}};
    vector<string> res;
    string path;
    void backtracking(const string& digits) {
        if (path.size()==digits.size()) {
            res.push_back(path);
            return;
        }
        for (int i=0;i<m[int(digits[path.size()])-48].size();++i) {
            path.push_back(char(m[int(digits[path.size()])-48][i]));
            backtracking(digits);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        path="";
        if (digits=="") return res;
        backtracking(digits);
        return res;
    }
};
// @lc code=end

