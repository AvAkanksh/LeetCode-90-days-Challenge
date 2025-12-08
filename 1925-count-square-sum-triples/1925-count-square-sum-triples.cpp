class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j<= n ; j++){
                int k = i*i+j*j;
                int sqrt_k = sqrt(k);
                if(k==sqrt_k*sqrt_k and sqrt_k<=n){
                    // cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};