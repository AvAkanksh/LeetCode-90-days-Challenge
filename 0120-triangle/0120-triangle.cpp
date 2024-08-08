class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1){
            return triangle[0][0];
        }
        vector<vector<int>>dp(n,vector<int>(n,0));
        int ans = INT_MAX;
        dp[0][0] = triangle[0][0];
        for(int i =1 ; i<n; i++){
            for(int j = 0 ;j<=i; j++){
                if(j==0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                    // cout<<"Case 1 : "<<dp[i][j]<<"|";
                }
                else if(j==i){
                    dp[i][j] = dp[i-1][j-1]+ triangle[i][j];
                    // cout<<"Case 2 : "<<dp[i][j]<<"|";
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
                    // cout<<"Case 3 : "<<dp[i][j]<<"|"; 
                    
                }
                if(i==n-1){
                    ans = min(ans,dp[i][j]);
                }
            }
                cout<<endl;
        }
        return ans;
        
    }
};