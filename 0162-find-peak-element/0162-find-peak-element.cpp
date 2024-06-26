static auto fastio = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        fastio();
        int n = nums.size();
        if(n==1){
            return 0; 
        }
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid>0 and mid<n-1){
                if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]){
                    return mid;
                }else if(nums[mid-1]>nums[mid]){
                    high = mid-1;
                }else {
                    low = mid+1;
                }
            }else{
                if(mid==0){
                    if(nums[0]>nums[1]){
                        return 0;
                    }else{
                        return 1;
                    }
                }else if(mid==n-1){
                    if(nums[n-1]>nums[n-2]){
                        return n-1;
                    }else{
                        return n-2;
                    }
                }
            }
        }
        return -1;
    }
};