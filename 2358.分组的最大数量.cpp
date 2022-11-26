/*
 * @lc app=leetcode.cn id=2358 lang=cpp
 *
 * [2358] 分组的最大数量
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
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int low = 1, high = 500;
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (n < (1 + mid) * mid / 2) high = mid - 1;
            else if (n > (mid + 1) * (mid + 2) / 2 - 1) low = mid + 1;
            else break;
        }
        return mid;
    }
};
// @lc code=end

