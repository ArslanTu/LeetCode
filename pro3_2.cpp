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
	vector<int> memos;
	map<int, vector<int>> ids;
public:
    Allocator(int n) {
		memos = vector<int>(n);
    }
    
    int allocate(int size, int mID)
    {
        if (size > memos.size()) return -1;
        for (int i = 0; i < memos.size() - size + 1; ++i) {
            bool found = true;
            for (int j = i; j < i + size; ++j) {
                if (memos[j] != 0) {
                    found = false;
                    break;
                }
            }
            if (found) {
                for (int j = i; j < i + size; ++j) {
					memos[j] = mID;
					ids[mID].push_back(j);
				}
                return i;
            }
        }
        return -1;
    }

    int free(int mID)
    {
        int cnt = ids[mID].size();
		for (auto& tag : ids[mID]) memos[tag] = 0;
		ids.erase(mID);
        return cnt;
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