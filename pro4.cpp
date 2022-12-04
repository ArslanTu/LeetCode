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
#include <numeric>
using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> access(n + 1, 0);
        vector<int> pushIn(n + 1, 0);
		vector<vector<int>> pic(n + 1, vector<int>());
		for (auto& edge : edges) {
			pic[edge[0]].push_back(edge[1]);
			pic[edge[1]].push_back(edge[0]);
		}
		vector<int> childNumIn(n + 1, 0);
		for (int i = 1; i < n + 1; ++i) childNumIn[i] = i;
		static auto cmp = [&](int a, int b)->bool {
			return pic[a].size() <= pic[b].size();
		};
		int ans = 0;
		sort(childNumIn.begin() + 1, childNumIn.end(), cmp);


		queue<int> que;
		for (int i = 1; i < n + 1 && !access[childNumIn[i]]; ++i) {
			que.push(childNumIn[i]);
			pushIn[childNumIn[i]] = 1;
			while (!que.empty()) {
				++ans;
				int size = que.size();
				for (int i = 0; i < size; ++i) {
					int cur = que.front();
					que.pop();
					access[cur] = 1;
					for (auto& next : pic[cur]) {
						if (!access[next] && !pushIn[next]) {
							que.push(next);
							pushIn[next] = 1;
						}
					}
				}
			}
		}
		return ans;
    }
};

int main() {
	Solution solution;

	vector<vector<int>> edges = {{1,2},{1,4},{1,5},{2,6},{2,3},{4,6}};
	solution.magnificentSets(6, edges);

	return 0;
}