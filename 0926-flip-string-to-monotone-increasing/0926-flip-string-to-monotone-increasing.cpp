class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0;
        int one = 0;
        for(auto x:s){
            if(x=='1'){
                one++;
            }
            else{
                ans = min(ans+1,one);
            }
        }
        return ans;
    }
};