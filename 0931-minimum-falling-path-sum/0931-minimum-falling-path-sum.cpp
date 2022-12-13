class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector< vector<int> > dp(n,vector<int> (n,0));
        int ans = INT_MAX;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                int num = 100001;
                if(i==0){
                    dp[i][j] = matrix[i][j];
                }
                else{
                    if(i-1>=0){num=min(num,dp[i-1][j]);}
                    if((i-1>=0) && (j-1>=0)){num=min(num,dp[i-1][j-1]);}
                    if((i-1>=0) && (j+1<n)){num=min(num,dp[i-1][j+1]);}
                    dp[i][j] = num+matrix[i][j];   
                }
            }
        }
        
        for(auto x : dp[n-1]){
            ans = min(ans,x);
        }
       return ans;
    }
};