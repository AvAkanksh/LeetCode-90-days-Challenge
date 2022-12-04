class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long> runningSum(nums.size(),0);
        runningSum[0] = nums[0];
        for(int i = 1 ; i<n ; i++){
            runningSum[i] = runningSum[i-1]+nums[i];
        }
        int ans = INT_MAX;
        int index = 0;
        for(int i = 0 ; i<n; i++){
            if(i==n-1){
                if(runningSum[n-1]/n<ans){
                    index = i;
                }
            }
            else{
                int leftSum = runningSum[i]/(i+1);
                int rightSum = (runningSum[n-1] - runningSum[i])/(n-i-1);
                if(abs(leftSum-rightSum)<ans){
                    ans = abs(leftSum-rightSum);
                    index = i;
                }
            }
        }
        return index;
    }
};