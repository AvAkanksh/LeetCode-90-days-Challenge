class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        for(int i = 1 ; i<n ; i++){
            if(nums[count-1]==nums[i]){
                continue;
            }
            nums[count] = nums[i];
            count++;
        }
        return count;
    }
};