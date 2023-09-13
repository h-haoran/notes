/*
 * @lc app=leetcode id=2767 lang=cpp
 *
 * [2767] Partition String Into Minimum Beautiful Substrings
 */

// @lc code=start
#include <string>
#include <cmath>
#include <vector>
using namespace std;
class Solution {
public:
    bool is5(int n) {
        float res1 = log(n) / log(5);
        return res1==floor(res1);
    }
    int substr2int(string &s, int b, int e) {
        return stoi(s.substr(b, e-b+1), nullptr, 2);
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        vector<int>  dp(n,-1);
        dp[0] = s[0] == '0'? -1:1;
        for (int i = 1; i < n; i++) {
            // cout << substr2int(s,0,i) << endl;
            if (s[0]!= '0' && is5(substr2int(s,0,i))) {
                dp[i] = 1;
            } else {
                for (int e = i; e > 0; e--) {
                    if (s[e] != '0') {
                        if (dp[e-1] != -1 && is5(substr2int(s,e,i))) {
                            dp[i] = dp[i] == -1 ? dp[e-1] + 1: min(dp[e-1] + 1, dp[i]);
                        }
                    }
                }
            }
        }
        // for (int n:dp) cout << n << " ";
        // cout << endl; 
        return dp[n-1];
    }
};
// @lc code=end

