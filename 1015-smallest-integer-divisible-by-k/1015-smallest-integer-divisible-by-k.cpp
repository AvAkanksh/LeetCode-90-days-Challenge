class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) return 1;
        int ans = 0;
        int rem = 1%k;
        while(rem != 0){
            ans++;
            rem = (rem*10 + 1)%k;
            if (ans>100000){
                return -1;
            }
        }
        return ans+1;

    }
};