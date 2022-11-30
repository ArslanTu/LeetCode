/*
 * @lc app=leetcode.cn id=2332 lang=cpp
 *
 * [2332] 坐上公交的最晚时间
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
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int j = 0, c;
        for (int t : buses)
            for (c = capacity; c && j < passengers.size() && passengers[j] <= t; --c)
                ++j;
        --j;
        int ans = c ? buses.back() : passengers[j]; // 在发车时到达公交站 or 上一个上车的乘客
        while (j >= 0 && passengers[j--] == ans) --ans; // 往前找没人到达的时刻
        return ans;
    }
};
// @lc code=end

