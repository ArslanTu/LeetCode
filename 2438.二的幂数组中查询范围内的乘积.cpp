/*
 * @lc app=leetcode.cn id=2438 lang=cpp
 *
 * [2438] 二的幂数组中查询范围内的乘积
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
private:
    int maxMi(int x) {
        int y=1;
        while (y<=x) {
            y*=2;
        }
        return y/2;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powersReverse;
        while (n!=0) {
            int x=maxMi(n);
            powersReverse.push_back(x);
            n-=x;
        }
        vector<int> powers(powersReverse.rbegin(),powersReverse.rend());
        vector<int> ans(queries.size());
        for (int i=0;i<queries.size();++i) {
            long long res=1;
            for (int j=queries[i][0];j<=queries[i][1];++j) {
                res*=powers[j]%(1000000007LL);
                res%=(1000000007LL);
            }
            ans[i]=res;
        }
        return ans;
    }
};
// @lc code=end

