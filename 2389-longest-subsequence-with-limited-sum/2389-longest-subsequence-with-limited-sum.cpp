class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        // vector<int> prefixSum(nums.size());
        // prefixSum[0] = nums[0];
        for(int i = 1 ; i<nums.size() ; i++){
            nums[i] += nums[i-1];
        }
        vector<int> ans;
        for(auto x: queries){
            ans.push_back(upper_bound(nums.begin(),nums.end(),x)-nums.begin());
        }
        return ans;
    }
};