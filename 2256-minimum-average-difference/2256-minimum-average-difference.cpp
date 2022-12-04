class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long totalSum = 0;
        for(int i = 0 ; i<n ; i++){
            totalSum += nums[i];
        }
        int ans = INT_MAX;
        int index = 0;
        long currSum =0;
        for(int i = 0 ; i<n; i++){
            if(i==n-1){
                if(totalSum/n<ans){
                    index = i;
                }
            }
            else{
                currSum += nums[i];
                int leftSum = currSum/(i+1);
                int rightSum = (totalSum - currSum)/(n-i-1);
                // cout<<"leftSum"<<leftSum<<endl    
                if(abs(leftSum-rightSum)<ans){
                    ans = abs(leftSum-rightSum);
                    index = i;
                }
            }
            
        }
        return index;
    }
};