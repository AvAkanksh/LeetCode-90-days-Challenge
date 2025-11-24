class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>v;
        long long num = 0;
        for(auto x : nums){
            num = ((num<<1)+x)%5;
            v.push_back((num%5)==0);
        }
        return v;
    }
};