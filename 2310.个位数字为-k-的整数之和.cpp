/*
 * @lc app=leetcode.cn id=2310 lang=cpp
 *
 * [2310] 个位数字为 K 的整数之和
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
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        if (k == 0) k = 10;
        for (int i = 1; i * k <= num; ++i) {
            if ((num - i *k) % 10 == 0) return i;
        }
        return -1;
    }
};
// @lc code=end

