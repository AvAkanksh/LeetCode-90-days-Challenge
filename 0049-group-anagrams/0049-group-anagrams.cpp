class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s : strs){
            string val = s;
            sort(s.begin(),s.end());
            mp[s].push_back(val);
        }
        vector<vector<string>> ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};