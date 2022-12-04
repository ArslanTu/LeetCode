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

// class Solution {
// private:
// 	void dfs(int cur, int pre, vector<vector<int>>& pic, map<vector<int>, int>& dis, map<vector<int>, int>& done, int& ans) {
// 		if (done[{pre, cur}] || done[{cur, pre}]) return;
// 		else {
// 			done[{pre, cur}] = 1;
// 			done[{cur, pre}] = 1;
// 		}
// 		int path = dis[{pre, cur}];
// 		if (path == 0) path = INT_MAX;
// 		ans =  path < ans ? path : ans;
// 		for (auto& next : pic[cur]) {
// 			if (next != pre) {
// 				dfs(next, cur, pic, dis, done, ans);
// 			}
// 		}
// 	}
// public:
//     int minScore(int n, vector<vector<int>>& roads) {
//         vector<vector<int>> pic(n + 1, vector<int>());
// 		map<vector<int>, int> dis;
// 		map<vector<int>, int> done;
// 		for (auto& road : roads) {
// 			pic[road[0]].push_back(road[1]);
// 			dis[{road[0], road[1]}] = road[2];
// 			pic[road[1]].push_back(road[0]);
// 			dis[{road[1], road[0]}] = road[2];
// 		}
// 		int ans = INT_MAX;
// 		dfs(1, -1, pic, dis, done, ans);
// 		return ans;
//     }
// };

class Solution {
private:
	void dfs(int pre, int cur, vector<vector<int>>& pic, unordered_set<int>& access) {
		if (access.count(cur)) return;
		access.emplace(cur);
		for (auto& next : pic[cur]) {
			if (cur != pre) {
				dfs(cur, next, pic, access);
			}
		}
	}
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> pic(n + 1, vector<int>());
		for (auto& road : roads) {
			pic[road[0]].push_back(road[1]);
			pic[road[1]].push_back(road[0]);
		}
		unordered_set<int> access;

		dfs(-1, 1, pic, access);

		int ans = INT_MAX;
		for (auto& road : roads) {
			if (access.count(road[0]) && access.count(road[1])) ans = ans < road[2] ? ans : road[2];
		}
		return ans;
    }
};

int main() {
	Solution solution;
	vector<vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
	int x =solution.minScore(4, roads);
	return 0;
}