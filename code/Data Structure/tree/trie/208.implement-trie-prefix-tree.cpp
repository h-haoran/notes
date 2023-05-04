/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Trie {
    bool isWord;
    vector<Trie*> children;
public:
    Trie() {
        isWord = false;
        children = vector<Trie*>(26, nullptr);
    }
    
    void insert(string word) {
        Trie* t = this;
        int i = 0;
        while (i < word.size()) {
            Trie* c = t->children[word[i] - 'a'];
            if (!c) {
                t->children[word[i] - 'a'] = new Trie();
            }
            t = t->children[word[i] - 'a'];
            i++;
        }
        t->isWord = true;
    }
    
    bool search(string word) {
        Trie* t = this;
        int i = 0;
        while (t && i < word.size()) {
            t = t->children[word[i] - 'a'];
            i++;
        }
        return t && t->isWord == true;
    }
    
    bool startsWith(string prefix) {
        Trie* t = this;
        int i = 0;
        while (t && i < prefix.size()) {
            t = t->children[prefix[i] - 'a'];
            i++;
        }
        return t;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("word");
    obj->insert("world");

    bool ans1 = obj->search("word");
    bool ans2 = obj->startsWith("wor");
    cout << ans1 << ans2 << endl;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

