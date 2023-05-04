/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isMatch(char a, char b) {
        switch(a) {
            case '(': return b==')';
            case '[': return b==']';
            case '{': return b=='}'; 
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> stk;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty() || !isMatch(stk.top(),c)) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return !stk.size() ;
    }
};
// @lc code=end

