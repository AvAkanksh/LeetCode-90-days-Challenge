class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0];
        int second = cost[1];
        for(int i = 2 ; i< cost.size() ; i++){
            int curr = cost[i] + min(first,second);
            first = second;
            second = curr;
        }
        return min(first,second);
    }
};