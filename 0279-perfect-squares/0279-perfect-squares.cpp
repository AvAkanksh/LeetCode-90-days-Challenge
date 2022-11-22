class Solution {
public:
    int numSquares(int n) {
        if(floor(sqrt(n))==ceil(sqrt(n))){
            return 1;
        }
        while(n%4==0){
            n /= 4;
        }
        if(n%8==7){
            return 4;
        }
        for(int i  = 1 ; i*i<=n ; i++){
            int sq = i*i;
            if(ceil(sqrt(n-sq))==floor(sqrt(n-sq))){
                return 2;
            }
        }
        return 3;
    }
};