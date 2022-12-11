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
    int deleteGreatestValue(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size(), ans = 0;
        for (auto& row : grid) sort(row.begin(), row.end());
		for (int i = n - 1; i >= 0; --i) {
			int maxNum = INT_MIN;
			for (int j = 0; j < m; ++j) {
				maxNum = maxNum > grid[j][i] ? maxNum : grid[j][i];
			}
			ans += maxNum;
		}
		return ans;
    }
};