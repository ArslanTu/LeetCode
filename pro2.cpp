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
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
		int sum = 0;
		unordered_map<int, int> mp;
		for(auto& num : skill) {
			mp[num]++;
			sum += num;
		}
		if (sum % (n >> 1) != 0) return -1;

		int teamSum = sum / (n >> 1);
		long long ans = 0LL;
		for (int i = 0; i < n; ++i) {
			int s1 = skill[i], s2 = teamSum - s1;
			if (mp[s1]) {
				--mp[s1];
				if(!mp[s2]) return -1;
				else {
					--mp[s2];
					ans += s1 * s2;
				}
			}
		}
		return ans;
    }
};

int main() {
	Solution solution;
	vector<int> skill = {1,1,2,3};
	int x = solution.dividePlayers(skill);


	return 0;
}