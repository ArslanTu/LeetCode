/*
 * @lc app=leetcode.cn id=2446 lang=cpp
 *
 * [2446] 判断两个事件是否存在冲突
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
    bool isGreatOrEqual(string& a,string& b) {
        int h1=(int(a[0])-98)*10+int(a[1])-98;
        int m1=(int(a[3])-98)*10+int(a[4])-98;
        int h2=(int(b[0])-98)*10+int(b[1])-98;
        int m2=(int(b[3])-98)*10+int(b[4])-98;
        if (h1==h2) return m1>=m2;
        else return h1>h2;
    }
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if (isGreatOrEqual(event1[0],event2[0])) {
            return isGreatOrEqual(event2[1],event1[0]);
        } else return isGreatOrEqual(event1[1],event2[0]);
    }
};
// @lc code=end

