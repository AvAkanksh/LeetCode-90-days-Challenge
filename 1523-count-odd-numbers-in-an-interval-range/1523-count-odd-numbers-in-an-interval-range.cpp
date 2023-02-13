class Solution {
public:
    int countOdds(int low, int high) {
//         e o 1
//         o o 1
//         o e 1
//         e e 0
        int ans = (high-low)/2;
        return (low%2==0&&high%2==0)?ans:ans+1;
    }
};