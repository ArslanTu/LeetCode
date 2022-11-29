/*
 * @lc app=leetcode.cn id=2336 lang=cpp
 *
 * [2336] 无限集中的最小数字
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
class SmallestInfiniteSet {
private:
    set<int> before;
public:
    SmallestInfiniteSet() {
        before.clear();
        before.emplace(1);
    }
    
    int popSmallest() {
        int x = *before.begin();
        if (before.size() == 1) before.emplace(x + 1);
        before.erase(before.begin());
        return x;
    }
    
    void addBack(int num) {
        if (num < *before.rbegin()) before.emplace(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

