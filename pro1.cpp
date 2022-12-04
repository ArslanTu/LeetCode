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
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
		if (sentence[0] != sentence[n - 1]) return false;
		for (int i = 0; i < n; ++i) {
			if (sentence[i] == ' ') {
				if (sentence[i - 1] != sentence[i + 1]) return false;
			}
		}
		return true;
    }
};

int main() {
	Solution solution;

	string s = "leetcode exercises sound delightful";
	bool b = solution.isCircularSentence(s);

	return 0;
}