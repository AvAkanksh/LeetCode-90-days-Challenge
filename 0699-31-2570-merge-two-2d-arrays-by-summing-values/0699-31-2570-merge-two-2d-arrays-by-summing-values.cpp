class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> mp;
        for(auto i : nums1){
            mp[i[0]] += i[1];
        }
        for(auto i : nums2){
            mp[i[0]] += i[1];
        }
        
        vector<vector<int>>ans;
        for(auto x : mp){
            ans.push_back({x.first,x.second});
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};