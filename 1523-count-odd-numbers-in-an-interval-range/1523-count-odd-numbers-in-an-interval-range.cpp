class Solution {
public:
    int countOdds(int low, int high) {
//         e o 1
//         o o 1
//         o e 1
//         e e 0
        bool l = low%2==0;
        bool r = high%2==0;
        if(l==true){
            if(r==true){
                return (high-low)/2;
            }
            else{
                return (high-low)/2+1;
            }
        }
        else{
            if(r==true){
                return (high-low)/2+1;
            }
            else{
                return (high-low)/2+1;
            }
        }
    }
};