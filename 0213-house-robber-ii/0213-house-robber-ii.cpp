class Solution {
public:
    int helper(int start, vector<int>&nums){
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        dp[1] = nums[start];
        for(int i = 2; i<=n-1; i++){
            // cout<<"i: "<<i<<"i-2 : "<<i-2<<"i+start :"<<i+start<<endl;
            dp[i] = max(dp[i-2]+nums[i+start-1],dp[i-1]);
        }
        cout<<dp[n-1]<<endl;
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int ans1 = helper(0,nums);
        int ans2 = helper(1,nums);
        
        return max(ans1,ans2);
    }
};