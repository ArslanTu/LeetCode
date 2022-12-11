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
    int longestSquareStreak(vector<int>& nums) {
		set<int> s(nums.begin(), nums.end());
		nums = vector<int>(s.begin(), s.end());
		int n = nums.size(), ans = 0;
		unordered_set<int> visited;
		int i = 0, cnt = 1;
		long long cur = nums[0];
		while (i < n) {
			if (visited.count(cur) != 0) {
				cur = nums[i++];
			}
			else {
				visited.emplace(cur);
				if (binary_search(nums.begin(), nums.end(), cur * cur)) {
					cur *= cur;
					cnt++;
					ans = ans > cnt ? ans : cnt;
				}
				else {
					cur = nums[i++];
					cnt = 1;
				}
			}
		}
		return ans == 0 ? -1 : ans;
    }
};

int main(){
	Solution solution;
	vector<int> nums = {4,3,6,16,8,2};
	solution.longestSquareStreak(nums);
	return 0;
}