/*
 * @lc app=leetcode.cn id=2400 lang=cpp
 *
 * [2400] 恰好移动 k 步到达某一位置的方法数目
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
    const int MOD = 1000000007;

public:
    int numberOfWays(int startPos, int endPos, int K) {
        int d = abs(startPos - endPos);
        if ((d + K) % 2 == 1 || d > K) return 0;
        // 递推求组合数
        vector<vector<long long>> f;
        f.resize(K + 1, vector<long long>(K + 1));
        for (int i = 0; i <= K; i++) {
            f[i][0] = 1;
            for (int j = 1; j <= i; j++) f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
        }
        return f[K][(d + K) / 2];
    }
};
// @lc code=end

