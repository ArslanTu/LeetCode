/*
 * @lc app=leetcode.cn id=2349 lang=cpp
 *
 * [2349] 设计数字容器系统
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
class NumberContainers {
private:
    unordered_map<int, int> indexToNum;
    unordered_map<int, set<int>> numToIndex;
public:
    NumberContainers() {

    }
    
    void change(int index, int number) {
        int originNum = indexToNum[index];
        if (originNum) numToIndex[originNum].erase(index);
        indexToNum[index] = number;
        numToIndex[number].emplace(index);
    }
    
    int find(int number) {
        int index = -1;
        if (numToIndex[number].begin() != numToIndex[number].end()) index = *(numToIndex[number].begin());
        return index;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end

