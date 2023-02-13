class Solution {
public:
    int countOdds(int low, int high) {
//         e o 1
//         o o 1
//         o e 1
//         e e 0
        return (low%2==0&&high%2==0)?(high-low)/2:(high-low)/2+1;
    }
};