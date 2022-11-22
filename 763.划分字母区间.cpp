/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> right(26);
        for (int i=0;i<s.size();++i) right[int(s[i])-97]=i;
        vector<int> res;
        int start=-1;
        int des=-1;
        for (int i=0;i<s.size();++i) {
            if (start==-1) {
                start=i;
                des=right[int(s[i])-97];
            }
            des=des>right[int(s[i])-97]?des:right[int(s[i])-97];
            if (des==i) {
                res.push_back(des-start+1);
                start=-1;
                des=-1;
            }
        }
        return res;
    }
};
// @lc code=end

