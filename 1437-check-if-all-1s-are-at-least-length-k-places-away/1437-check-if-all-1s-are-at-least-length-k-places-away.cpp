class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // int i = 0 ;
        // int j = 0;
        int n = nums.size();
        bool isFirstOne = true;
        int previousOne = -1;
        int currOne = -1;
        for(int i = 0 ; i< n  ;i++){
            // cout<<nums[i]<<endl;
            if(nums[i]==1){
                if(isFirstOne){
                    // cout<<"first 1:"<<endl;
                    isFirstOne = false;
                    previousOne = i;
                }else{
                    currOne = i;
                    // cout<<"i-previous_i : "<<currOne-previousOne<<endl;
                    if(currOne-previousOne-1<k){
                        return false;
                    }
                    previousOne = i;
                }
            }
        }
        return true;
    }
};