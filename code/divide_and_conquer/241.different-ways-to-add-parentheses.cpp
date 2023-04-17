/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> dfs(string expression, int l, int r){
        vector<int> res;
        for(int i = l; i <= r; ++i){
            if(expression[i] >= '0' and expression[i] <= '9') continue;
            else{
                vector<int> left = dfs(expression, l, i - 1);
                vector<int> right = dfs(expression, i + 1, r);
                for(auto le: left){
                    for(auto ri: right){
                        int tmp = 0;
                        if(expression[i] == '+') tmp = le + ri;
                        if(expression[i] == '-') tmp = le - ri;
                        if(expression[i] == '*') tmp = le * ri;
                        res.emplace_back(tmp);
                    }
                }
            }
        }
        if(res.empty()){
            int tmp = 0;
            for(int i = l; i <= r; ++i) tmp = tmp * 10 + (expression[i] - '0');
            res.emplace_back(tmp);
        }
        return res;
    }

    vector<int> diffWaysToCompute(string expression) {
        int len = expression.length();
        return dfs(expression, 0, len - 1);
    }
};
// @lc code=end

