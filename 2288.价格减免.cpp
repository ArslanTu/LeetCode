/*
 * @lc app=leetcode.cn id=2288 lang=cpp
 *
 * [2288] 价格减免
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
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

// @lc code=start
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ans = "";
        auto newPrice = [&](long price, int discount)->string {
            double p = price * (100 - discount) * 0.01;
            stringstream ss;
            ss << setiosflags(ios::fixed) << setprecision(2) << p;
            string s = "$" + ss.str();
            return s;
        };
        int n = sentence.size();
        for (int i = 0; i < n;) {
            if (sentence[i] == '$' && (i == 0 || sentence[i - 1] == ' ') && i < n - 1 && (sentence[i + 1] - '0' >= 0 && sentence[i + 1] - '0' < 10) ) {
                ++i;
                long sum = 0;
                string temp = "$";
                bool isTrue = true;
                while (sentence[i] != ' ' && i < n) {
                    if (sentence[i] - '0' >= 0 && sentence[i] - '0' < 10) {
                        temp += sentence[i];
                        sum = sum * 10 + (sentence[i] - '0');
                        ++i;
                    }
                    else {
                        isTrue = false;
                        break;
                    }
                }
                if (isTrue) ans += newPrice(sum, discount);
                else ans += temp;
            }
            else {
                ans += sentence[i];
                ++i;
            }
        }
        return ans;
    }
};
// @lc code=end

