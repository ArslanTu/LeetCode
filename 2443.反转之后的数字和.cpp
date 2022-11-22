/*
 * @lc app=leetcode.cn id=2443 lang=cpp
 *
 * [2443] 反转之后的数字和
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
#include <math.h>
using namespace std;
class Solution {
private:
    int revert(int x) {
        int y=0;
        while(x) {
            y=y*10+x%10;
            x/=10;
        }
        return y;
    }
public:
    bool sumOfNumberAndReverse(int num) {
        for (int start=num/2;start<=num;++start) if (start+revert(start)==num) return true;
        return false;
    }
};
// @lc code=end

