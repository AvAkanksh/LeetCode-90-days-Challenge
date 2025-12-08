class Solution {
public:
    bool check(int mid, vector<int>& nums, int threshold){
        int ans = 0;
        for(auto x : nums){
            ans+=(x+mid-1)/mid;
        }
        return ans<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = INT_MAX;
        int h = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            l = min(l,nums[i]);
            h = max(h,nums[i]);
        }
        // cout<<
        int ans = INT_MAX;
        while(l<=h){
            int mid = (l+h)/2;
            if(check(mid,nums,threshold)){
                ans = min(ans,mid);
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};