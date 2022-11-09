class Solution {
public:
    int bsf(vector<int> &nums, int target){
        int first = -1;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(nums[mid]== target){
                first = mid;
                r = mid-1;
            }
            else{
                if(nums[mid]<target){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return first;
    }
    
    int bsl(vector<int> &nums, int target){
        int last = -1;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(nums[mid]== target){
                last = mid;
                l = mid+1;
            }
            else{
                if(nums[mid]<target){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return last;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // int first = bsf(nums,target);
        // int last = bsl(nums,target);
        // vector<int> ans = {first,last};
        // return ans;
        
        auto stlfirst = lower_bound(nums.begin(),nums.end(),target);
        auto stllast = upper_bound(nums.begin(),nums.end(),target);
        
        if(stlfirst == nums.end() || *stlfirst != target){return {-1,-1} ;}
        else{
            
            vector<int> ans = {int(stlfirst-nums.begin()), int(stllast-nums.begin())-1};
            return ans;
        }
    }
};