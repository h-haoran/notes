/*
 * @lc app=leetcode id=2801 lang=cpp
 *
 * [2801] Count Stepping Numbers in Range
 */

// @lc code=start
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int M = 1000000007;
class Solution {
public:
    bool checkS(string s) {
        if (s.size() <= 1) return true;
        for (int i = 1; i < s.size(); i++) {
            if (abs(s[i]-s[i-1]) != 1) {
                return false;
            }
        }
        return true;
    }

    int helper(string s) {
        int n = s.size();
        // int dp[n][10][2][2]; // len/ 10 digits/ isLeadingZero/ isMax
        int dp[n][10][3]; // 3 cases: [0]:leading zero(cant be max) [1]:non leading zero isMax [2]:non leading zero not max 
        memset(dp, 0, sizeof(dp));
        
        dp[0][0][0] = 1;
        for (int d = 1; d < s[0]-'0'; d++) {
            dp[0][d][2] = 1;
        }
        dp[0][s[0] - '0'][1] = 1;

        for (int i = 1; i < n; i++) {
            for (int d = 0; d < 10; d++) {
                if (d == 0) {
                    dp[i][d][0] = dp[i-1][0][0];
                }

                if (d == s[i] - '0') {
                    if (d != 0) dp[i][d][2] = dp[i-1][0][0] % M;
                    if (d-1 >= 0) {
                        dp[i][d][2] += dp[i-1][d-1][2] % M;
                        dp[i][d][1] = dp[i-1][d-1][1]; 
                    }
                    if (d+1 <= 9) {
                        dp[i][d][2] += dp[i-1][d+1][2] % M;
                        if (dp[i-1][d+1][1]) dp[i][d][1] = dp[i-1][d+1][1];  // not overwrite with 0
                    }
                } else if (d > s[i] - '0') {
                        if (d != 0) dp[i][d][2] = dp[i-1][0][0];
                        if (d-1 >= 0) {
                            dp[i][d][2] += dp[i-1][d-1][2] % M; 
                        }
                        if (d+1 <= 9) {
                            dp[i][d][2] += dp[i-1][d+1][2] % M; 
                        }
                } else {
                        if (d != 0) dp[i][d][2] = dp[i-1][0][0] % M;
                        if (d-1 >= 0) {
                            dp[i][d][2] += (dp[i-1][d-1][1] % M + dp[i-1][d-1][2] % M) % M; 
                        }
                        if (d+1 <= 9) {
                            dp[i][d][2] += (dp[i-1][d+1][1] % M + dp[i-1][d+1][2] % M) % M; 
                        }
                }
            }    
        }
        // for (int i = 0; i < n; i++) {
        //     for (int d = 0; d < 10; d++) {
        //         cout << "[" << dp[i][d][0] << "," << dp[i][d][1] << "," <<  dp[i][d][2] << "]" << "  "; 
        //     }
        //     cout << endl;
        // }

        int rtn = 0;
        for (int d = 0; d <= 9; d++) {
            rtn = rtn % M;
            rtn += (dp[n-1][d][1] % M) + (dp[n-1][d][2] % M) % M;
        }
        return rtn % M;
    }
    int countSteppingNumbers(string low, string high) {
        return (helper(high) + M - helper(low) + checkS(low)) % M;
    }
};
// @lc code=end

