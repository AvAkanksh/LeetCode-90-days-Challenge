class Solution {
public:
    int nCr(int n , int r){
        if(n<r){return 0;}
        vector<int> dp(r+1,0);
        dp[0] = 1;
        for(int i = 1 ; i <= n ; i++){
            for(int j = min(r,i) ; j>0 ; j--){
                dp[j] = dp[j]+dp[j-1];
            }
        }
        return dp[r];
        
    }
    
    int uniquePaths(int m, int n) {
        return nCr(n+m-2,min(n,m)-1);
    }
};