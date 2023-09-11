/*
 * @lc app=leetcode id=2746 lang=cpp
 *
 * [2746] Decremental String Concatenation
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int len = words.size(), rtn = INT_MAX;
        if (!len) return 0;
        if (len == 1) return words[0].size();
        int dp[1000][26][26];
        for (int i = 0; i < len; i++) {
            for(int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) { 
                    dp[i][j][k] = INT_MAX/2;
                }
            }
        }
        
        int s = words[0].front() - 'a';
        int e = words[0].back() - 'a';
        dp[0][s][e] = words[0].size();

      
        for (int i = 1; i < len; i++) {
            int s = words[i].front() - 'a';
            int e = words[i].back() - 'a';
            for(int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    int l = dp[i-1][j][k] + words[i].size();
                    int l1 = (j == e)? l-1:l;
                    int l2 = (k == s)? l-1:l;

                    dp[i][j][e] = min(dp[i][j][e], l2);
                    dp[i][s][k] = min(dp[i][s][k], l1);
                    if (i == (len-1)) {
                        rtn = min(min(rtn, l1),l2);
                    }
                }
            }
        }
        return rtn;
    }
};
// @lc code=end

