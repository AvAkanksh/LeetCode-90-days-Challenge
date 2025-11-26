class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;
        
        // dp[i][j][rem] = ways to reach (i,j) with sum % k == rem
        vector dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        // starting cell
        int startMod = grid[0][0] % k;
        dp[0][0][startMod] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int currMod = grid[i][j] % k;

                // from top
                if (i > 0) {
                    for (int prev = 0; prev < k; prev++) {
                        if (dp[i-1][j][prev]) {
                            int newMod = (prev + currMod) % k;
                            dp[i][j][newMod] = (dp[i][j][newMod] + dp[i-1][j][prev]) % MOD;
                        }
                    }
                }
                // from left
                if (j > 0) {
                    for (int prev = 0; prev < k; prev++) {
                        if (dp[i][j-1][prev]) {
                            int newMod = (prev + currMod) % k;
                            dp[i][j][newMod] = (dp[i][j][newMod] + dp[i][j-1][prev]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};