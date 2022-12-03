/*
 * @lc app=leetcode.cn id=2296 lang=cpp
 *
 * [2296] 设计一个文本编辑器
 */
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

// @lc code=start
class TextEditor {
private:
    string s;
    int cursorPos;
public:
    TextEditor() {
        s = "";
        cursorPos = 0;
    }
    
    void addText(string text) {
        s = s.substr(0, cursorPos) + text + s.substr(cursorPos, s.size() - cursorPos);
        cursorPos += text.size();
    }
    
    int deleteText(int k) {
        int delLen;
        if (k >= cursorPos) {
            s = s.substr(cursorPos, s.size() - cursorPos);
            delLen = cursorPos;
            cursorPos = 0;
        }
        else {
            s = s.substr(0, cursorPos - k) + s.substr(cursorPos, s.size() - cursorPos);
            cursorPos -= k;
            delLen = k;
        }
        return delLen;
    }
    
    string cursorLeft(int k) {
        if (k >= cursorPos) {
            cursorPos = 0;
            return "";
        }
        else {
            cursorPos -= k;
            int subLen;
            if (cursorPos > 10) subLen = 10;
            else subLen = cursorPos;
            return s.substr(0 + cursorPos - subLen ,subLen);
        }
    }
    
    string cursorRight(int k) {
        if (k + cursorPos >= s.size()) cursorPos = s.size();
        else cursorPos += k;
        int subLen;
        if (cursorPos > 10) subLen = 10;
        else subLen = cursorPos;
        return s.substr(0 + cursorPos - subLen ,subLen);
        
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// @lc code=end

