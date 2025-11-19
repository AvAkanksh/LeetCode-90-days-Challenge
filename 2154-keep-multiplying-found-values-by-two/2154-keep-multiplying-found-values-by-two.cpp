class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x] ++;
        }

        while(mp.find(original)!=mp.end()){
            original=2*original;
        }
        return original;
    }
};