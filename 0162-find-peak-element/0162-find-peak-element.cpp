class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            // cout<<"n : "<<n<<" | mid : "<<mid<<endl;
            if((mid>0 && mid<(n-1) && (nums[mid]>nums[mid-1]) && (nums[mid]> nums[mid+1]))|| (mid==0 && nums[mid]>nums[mid+1]) ||(mid==n-1)&& nums[mid]>nums[mid-1]){
                return mid;
            }else if(nums[mid+1]>nums[mid]){
                low = mid+1;
            }else{
                high= mid;
            }
        }
        return -1;
    }

};