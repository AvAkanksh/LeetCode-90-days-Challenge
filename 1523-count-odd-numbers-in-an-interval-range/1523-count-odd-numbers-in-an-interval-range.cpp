class Solution {
public:
    int countOdds(int low, int high) {
//         e o 1
//         o o 1
//         o e 1
//         e e 0
        bool l = low%2==0;
        bool r = high%2==0;
        int ans = (high-low)/2;
        return (r&&l)?ans:ans+1;
    }
};