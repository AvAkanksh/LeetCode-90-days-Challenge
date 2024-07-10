class Solution {
public:
    void printdp(vector<vector<int>>&dp){
        for(auto x : dp){
            for(auto y : x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0 ; j<m ; j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[0][0];
                }else{    
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j>0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = min(up,left)+ grid[i][j];
                }

            }
        }
        // printdp(dp);
        return dp[n-1][m-1];
    }
};