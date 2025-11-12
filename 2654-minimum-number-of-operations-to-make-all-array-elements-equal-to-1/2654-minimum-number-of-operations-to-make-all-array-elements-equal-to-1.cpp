class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int all_gcd = nums[0];
        int number_ones = 0;
        for(auto &x : nums){
            if(x==1){
                number_ones ++;
            }
            all_gcd = __gcd(all_gcd, x);
        }
        if(all_gcd !=1){
            return -1;
        }
        if(number_ones!=0){
            return nums.size()-number_ones;
        }
        vector<int> v;
        bool flag = false;
        int height = 0;
        v = nums;
        vector<int> temp;
        while(!flag){
            height++;
            temp.clear();
            for(int i = 1 ; i<v.size() ; i++){
                if(__gcd(v[i-1],v[i])==1){
                    flag = true; 
                    break;
                }else{
                    temp.push_back(__gcd(v[i-1],v[i]));
                }
            }
            v = temp;

        }
        return nums.size()-1+height;


    }
};