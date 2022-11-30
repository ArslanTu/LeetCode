/*
 * @lc app=leetcode.cn id=2333 lang=cpp
 *
 * [2333] 最小差值平方和
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
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        map<int, int> mp;
        for (int i = 0; i < n; ++i) mp[abs(nums1[i] - nums2[i])]++;
        int k = k1 + k2;
        while (k > 0) {
            int key = mp.rbegin()->first;
            int cnt = mp.rbegin()->second;
            if (key == 0) return 0;
            if (k >= cnt) {
                k -= cnt;
                mp.erase(key);
                mp[key - 1] += cnt;
            } else {
                mp[key] = cnt - k;
                mp[key - 1] += k;
                k=0;
            }
        }
        long long ans = 0LL;
        for (auto& elem : mp) {
            long long x = (long long)(elem.first);
            long long cnt = (long long)(elem.second);
            ans += x * x * cnt;
        }
        return ans;
    }
};
// @lc code=end

