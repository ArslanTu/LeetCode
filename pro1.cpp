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

class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<set<char>, int> dics;
        for (auto& word : words) {
            set<char> s;
            for (auto& ch : word) {
                s.emplace(ch);
            }
			dics[s] += 1;
        }
		int ans = 0;
		for (auto& elem : dics) {
			if (elem.second > 1) ans += elem.second * (elem.second - 1) / 2;
		}
		return ans;
    }
};