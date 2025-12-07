class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0 ; 
        if(low%2==0 and high%2==0){
            return (high-low)/2;
        }else if(low%2 == 1 and high%2==0){
            return (high-low+1)/2;
        }else if(low%2 ==1 and high %2==1){
            return (high-low)/2 + 1;
        }else{
            return (high-low+1)/2;
        }
    }
};