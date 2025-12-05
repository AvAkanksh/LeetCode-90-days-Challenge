class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> prefixSum(nums.size(),0);
        prefixSum[0] = nums[0];
        for(int i = 1; i<nums.size() ; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int totalSum = prefixSum[nums.size()-1];
        int ans = 0;
        for(int i = 0 ; i<nums.size()-1 ; i++){
            int left = prefixSum[i];
            int right = totalSum - left;
            if(abs(left-right)%2==0){
                ans++;
            }
        }
        return ans;
    }
};