class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0;
        int totalGas =0;
        for(auto x : gas){
            totalGas+=x;
        }
        for(auto x: cost){
            totalCost+=x;
        }
        if(totalCost>totalGas){
            return -1;
        }
        int ans = 0;
        int tank = 0;
        for(int i = 0 ;i<gas.size() ;i++){
            tank += gas[i] - cost[i];
            if(tank <0){
                ans = i+1;
                tank = 0;
            }
            
        }
        return ans;
    }
};