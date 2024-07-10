class Solution {
public:
    int helper(vector<int>nums){
        int n = nums.size();
        int prev = 0;
        int prev2 = 0;
        for(int i = 0 ; i<n ; i++){
            int curr = max(prev,prev2+nums[i]);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> temp1(nums.begin()+1,nums.end());
        vector<int> temp2(nums.begin(),nums.end()-1);
        int ans1 = helper(temp1);
        int ans2 = helper(temp2);
        return max(ans1,ans2);
    }
};