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

#include <unordered_map>
#include <vector>

class Allocator {
public:
    Allocator(int n)
        : memos(n)
    {
    }

    int allocate(int size, int mID)
    {
        // 如果内存数组中没有足够的内存可用，返回 -1
        if (size > memos.size()) {
            return -1;
        }

        // 在内存数组中查找连续的 size 个空闲内存单元
        for (int i = 0; i < memos.size() - size + 1; ++i) {
            bool found = true;

            // 检查从 i 开始的连续 size 个内存单元是否都是空闲的
            for (int j = i; j < i + size; ++j) {
                if (memos[j] != 0) {
                    found = false;
                    break;
                }
            }

            if (found) {
                // 如果找到了空闲的内存，分配这些内存并返回起始下标
                for (int j = i; j < i + size; ++j) {
                    memos[j] = mID;
                }

                return i;
            }
        }

        // 如果没有找到空闲的内存，返回 -1
        return -1;
    }

    int free(int mID)
    {
        int count = 0;

        // 遍历内存数组，释放属于指定 ID 的内存单元
        for (int i = 0; i < memos.size(); ++i) {
            if (memos[i] == mID) {
                memos[i] = 0;
                ++count;
            }
        }

        return count;
    }

private:
    // 内存数组，0 表示空闲内存，非零的数字表示已被分配的内存
    vector<int> memos;
};
