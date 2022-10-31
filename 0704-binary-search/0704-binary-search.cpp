class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size();
        int mid;
        while(l<h){
            mid = (l+h)/2;
            if(nums[mid]==target){
                return mid;
            }
            else{
                if(nums[mid]>target){
                    h = mid;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};