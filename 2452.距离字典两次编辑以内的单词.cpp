/*
 * @lc app=leetcode.cn id=2452 lang=cpp
 *
 * [2452] 距离字典两次编辑以内的单词
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int m=queries.size(),n=dictionary.size();
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (queries[i].size()!=dictionary[j].size()) continue;
                int distance=0;
                for (int k=0;k<queries[i].size();++k) {
                    if (queries[i][k]!=dictionary[j][k]) {
                        ++distance;
                        if (distance>2) break;
                    }
                }
                if (distance<=2) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

