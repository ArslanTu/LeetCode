/*
 * @lc app=leetcode.cn id=2353 lang=cpp
 *
 * [2353] 设计食物评分系统
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
using namespace std;

// @lc code=start
// class FoodRatings {
// private:
//     unordered_map<string, pair<int, string>> foodToRateCus;
//     unordered_map<string, set<pair<int, string>>> cusToRateFood;
// public:
//     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//         for (int i = 0; i < foods.size(); ++i) {
//             foodToRateCus[foods[i]] = pair(-ratings[i], cuisines[i]);
//             cusToRateFood[cuisines[i]].emplace(pair(-ratings[i], foods[i]));
//         }
//     }
    
//     void changeRating(string food, int newRating) {
//         cusToRateFood[foodToRateCus[food].second].erase(pair(-foodToRateCus[food].first, food));
//         cusToRateFood[foodToRateCus[food].second].emplace(-newRating, food);
//         foodToRateCus[food].first = -newRating;
//     }
    
//     string highestRated(string cuisine) {
//         return cusToRateFood[cuisine].begin()->second;
//     }
// };

class FoodRatings {
    unordered_map<string, pair<int, string>> fs;
    unordered_map<string, set<pair<int, string>>> cs;
public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            auto &f = foods[i], &c = cuisines[i];
            int r = ratings[i];
            fs[f] = {r, c};
            cs[c].emplace(-r, f);
        }
    }

    void changeRating(string food, int newRating) {
        auto &[r, c] = fs[food];
        auto &s = cs[c];
        s.erase({-r, food}); // 移除旧数据
        s.emplace(-newRating, food); // 添加新数据
        r = newRating;
    }

    string highestRated(string cuisine) {
        return cs[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end

