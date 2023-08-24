#include <vector>
using namespace std;
class Solution {
public:
    int paintWalls(vector<int>& values, vector<int>& weights) {
        // kp
        int n = weights.size(); 
        int w = 3; // max weight

        // vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 0; j <= w; j++) {
        //         dp[i][j] = dp[i-1][j];
        //         int w_left = j - weights[i-1];
        //         if ( w_left >= 0) {
        //             dp[i][j] = max(dp[i][j], dp[i-1][w_left] + value[i-1]); 
        //         }
        //     }
        // }
        // return dp[n][w];
        // recursion
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        return helper(values, weights, w, n, dp);
    }
    int helper(vector<int>& value, vector<int>& weights, int weight, int idx, vector<vector<int>>& dp) {
        if (idx == 0) return 0;
        if (dp[idx][weight] != -1) return dp[idx][weight];

        dp[idx][weight] = helper(value, weights, weight, idx-1, dp);
        int w_left = weight - weights[idx-1];
        if (w_left >= 0) {
            dp[idx][weight] = max(dp[idx][weight], value[idx-1] + helper(value, weights, idx-1, w_left, dp));
        }
        return dp[idx][weight];
    }
};