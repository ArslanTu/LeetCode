/*
 * @lc app=leetcode.cn id=2311 lang=cpp
 *
 * [2311] 小于等于 K 的最长二进制子序列
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
#include <math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<int> zeroNum(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] == '0') {
                zeroNum[i] = zeroNum[i - 1] + 1;
            }
            else zeroNum[i] = zeroNum[i - 1];
        }
        long long num = 0LL;
        int pos = 0;
        int target = log(k) / log(2);
        int j = n - 1;
        for (; j >=0; --j) {
            if (s[j] == '1') {
                if (pos > target) break;
                else {
                    num += 1LL << pos;
                    if (num > k) break;
                }
                
            }
            pos += 1;
        }
        int zero = j < 0 ? 0 : zeroNum[j];
        return zero + n - j - 1;
    }
};
// @lc code=end

