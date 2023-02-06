class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int maxValue = 1001;
        int first = 0;
        int second = n;
        for(int i = 0 ; i<2*n ; i++){
            if(i%2==0){
                nums[i]+=(nums[first++]%maxValue)*maxValue;
            }
            else{
                nums[i]+=(nums[second++]%maxValue)*maxValue;
            }
        }
        for(int i = 0 ; i<2*n ; i++){
            nums[i]/=maxValue;
        }
        return nums;
    }
};