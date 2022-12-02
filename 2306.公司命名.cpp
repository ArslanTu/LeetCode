/*
 * @lc app=leetcode.cn id=2306 lang=cpp
 *
 * [2306] 公司命名
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0L;
        unordered_set<string> s(ideas.begin(), ideas.end());
        vector<vector<long long>> cnt(26, vector<long long>(26));
        for (auto& idea : ideas) {
            int pre = idea[0] - 'a';
            for (int i = 0; i < 26; ++i) {
                idea[0] = 'a' + i;
                if (!s.count(idea)) cnt[pre][i]++;
            }
        }

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans += cnt[i][j] * cnt[j][i];
            }
        }
        return ans;
    }
};
// @lc code=end

