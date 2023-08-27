/*
 * @lc app=leetcode id=2742 lang=cpp
 *
 * [2742] Painting the Walls
 */

// @lc code=start
#include <vector>
#include <climits>
using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        dp = vector<vector<int>>(n, vector<int>(n+1,-1));
        helper(cost, time, 0, n);
        // for (auto v: dp) {
        //     for (auto i:v) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        return dp[0][n];
    }
    int helper(vector<int>& cost, vector<int>& time, int idx, int wall_left) {
        if (wall_left <= 0)  return 0;
        if (idx >= cost.size()) {
            return INT_MAX/2;
        }
        if (dp[idx][wall_left] == -1) {
            dp[idx][wall_left] = min(cost[idx] + helper(cost, time, idx+1, wall_left-time[idx]-1), helper(cost, time, idx+1, wall_left));
        }
        return dp[idx][wall_left];
    }
};

class Solution2 {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = time.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1000000000));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                int t = min(n, j + time[i] + 1);
                dp[i+1][t] = min(dp[i+1][t], dp[i][j] + cost[i]);
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
        return dp[n][n];
    }
};
// @lc code=end

