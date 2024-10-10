class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n, INT_MIN);
        rightMax[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(nums[i], rightMax[i + 1]);
        }

        int i = 0;
        int res = INT_MIN;
        for(int j = 0; j < n; j++){
            while(nums[i] > rightMax[j]) i += 1;
            res = max(res, j - i);
        }
        return res;
    }
};