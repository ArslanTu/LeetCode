/*
 * @lc app=leetcode.cn id=2409 lang=cpp
 *
 * [2409] 统计共同度过的日子数
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
    const vector<int> dayOfMonth={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 定义a到b有多少天
    int totalDay(string a,string b) {
        int ans=0;
        int sum=0;
        int startMonth=(a[0]-'0')*10+(a[1]-'0');
        int endMonth=(b[0]-'0')*10+(b[1]-'0');
        int startDay=(a[3]-'0')*10+(a[4]-'0');
        int endDay=(b[3]-'0')*10+(b[4]-'0');
        int startMonthSurplus=startDay-1;
        int endMonthSurplus=dayOfMonth[endMonth-1]-endDay;
        for (int i=startMonth;i<=endMonth;++i) sum+=dayOfMonth[i-1];
        ans = sum-endMonthSurplus-startMonthSurplus;
        return ans<0?0:ans;
    }
    string maxDay(string a,string b) {
        if (a[0]-'0'>b[0]-'0') return a;
        if (a[0]-'0'==b[0]-'0'&&a[1]-'0'>b[1]-'0') return a;
        if (a[0]-'0'==b[0]-'0'&&a[1]-'0'==b[1]-'0'&&a[3]-'0'>b[3]-'0') return a;
        if (a[0]-'0'==b[0]-'0'&&a[1]-'0'==b[1]-'0'&&a[3]-'0'==b[3]-'0'&&a[4]-'0'>b[4]-'0') return a;
        return b;
    }

    string minDay(string a,string b) {
        if (maxDay(a,b)==a) return b;
        else return a;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string start=max(arriveAlice,arriveBob);
        string end=min(leaveAlice,leaveBob);
        return totalDay(start,end);
    }
};
// @lc code=end

