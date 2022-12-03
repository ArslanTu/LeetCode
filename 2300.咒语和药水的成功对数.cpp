/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        map<int, int> mp;
        sort(potions.begin(), potions.end());
        int n = potions.size();
        for (auto& spell : spells) {
            if (mp[spell]) {
                pairs.push_back(mp[spell]);
                continue;
            }
            int low = 0, high = n - 1;
            double target = (double)success / (double)spell;
            while (low <= high) {
                int mid = low + ((high - low) >> 1);
                if (potions[mid] == target) {
                    while (mid >=0 && potions[mid] == target) --mid;
                    low = mid + 1;
                    break;
                }
                else if (potions[mid] > target) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            pairs.push_back(n - low);
            mp[spell] = n - low;
        }
        return pairs;
    }
};
// @lc code=end

