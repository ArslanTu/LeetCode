/*
 * @lc app=leetcode.cn id=2416 lang=cpp
 *
 * [2416] 字符串的前缀分数和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
class TrieNode {
public:
    bool val;
    vector<TrieNode*> children;
    // 无参构造函数
    TrieNode() {
        val=false;
        vector<TrieNode*> newChildren(26,nullptr);
        children=newChildren;
    }
    // 插入字符串
    void insert(string& str,int index) {
        if (index==str.size()-1) return;
        if (this->children[str[index]-'a']==nullptr) {
            this->children[str[index]-'a']=new TrieNode;
        }
        this->children[str[index]-'a']->val=true;
        this->children[str[index]-'a']->insert(str,index+1);
    }
    // 查找字符串是否存在
    bool query(string& str,int index) {
        if (this->children[str[index]-'a']==nullptr) return false;
        if (index==str.size()-1&&this->children[str[index]-'a']->val==true) return true;
        if (index==str.size()-1&&this->children[str[index]-'a']->val==false) return false;
        return this->children[str[index]-'a']->query(str,index+1);

    }
    // 搜索指定字符串的最短前缀
    string shortestPrefix(string& str,int index) {
        if (this->children[str[index]-'a']==nullptr) return "";
        string s="";
        s+=str[index];
        if (this->children[str[index]-'a']->val==true) {
            return s;
        }
        return s+this->children[str[index]-'a']->shortestPrefix(str,index+1);
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        TrieNode* root=new TrieNode;
        for (int i=0;i<n;++i) root->insert(words[i],0);
    }
};
// @lc code=end

