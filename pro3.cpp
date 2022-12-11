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

class Allocator {
private:
	map<int, vector<vector<int>>> ids;
	vector<vector<int>> memos;
	int maxSize;
public:
    Allocator(int n) {
		maxSize = n;
    }
    
    int allocate(int size, int mID) {
		int start = 0;
		for (auto& block : memos) {
			if (block[0] - start >= size) break;
			else start = block[1];
		}
		if (maxSize - start < size) return -1;
		else {
			vector<int> newBlock = {start, start + size};
			ids[mID].push_back(newBlock);
			memos.push_back(newBlock);
			sort(memos.begin(), memos.end(), [&](vector<int> block1, vector<int> block2){
				return block1[0] < block2[0];
			});
			return start;
		}
    }
    
    int free(int mID) {
		if (ids.find(mID) == ids.end()) return 0;
		int size = 0;
		for (auto& block : ids[mID]) {
			size += block[1] - block[0];
			memos.erase(find(memos.begin(), memos.end(), block));
		}
		ids.erase(mID);
		return size;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

int main() {
	Allocator all(10);
	all.allocate(1, 1);
	all.allocate(1, 2);
	all.allocate(1, 3);
	all.free(2);
	all.allocate(3, 4);
	all.allocate(1, 1);
	all.allocate(1, 1);
	all.free(1);
	all.allocate(10, 2);
	all.free(7);
	return 0;
}