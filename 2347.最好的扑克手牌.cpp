/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 *
 * [2347] 最好的扑克手牌
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
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int m = unordered_set<char>(suits.begin(), suits.end()).size();
        if (m == 1) return "Flush";

        unordered_map<int, int> mp;
        for (auto& r : ranks) ++mp[r];
        int n = mp.size();
        if (n == 5) return "High Card";
        if (n < 3) return "Three of a Kind";
        for (auto& elem : mp) if (elem.second >= 3) return "Three of a Kind";

        return "Pair";

    }
};
// @lc code=end

