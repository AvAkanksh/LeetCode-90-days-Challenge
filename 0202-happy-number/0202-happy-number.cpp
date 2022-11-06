class Solution {
public:
    int sumSquare(int n){
        int sum = 0 ;
        while(n>0){
            sum+=pow(n%10,2);
            n=n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
    
        while(true){
            n = sumSquare(n);
            if(n==4){
                return false;
            }
            if(n==1){
                return true;
            }
        }
        return false;
    }
};