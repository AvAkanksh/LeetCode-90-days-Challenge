class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, vector<int> &temp, int startIndex){
        if(temp.size()>1) ans.push_back(temp);
        unordered_set<int> s;
        for(int i = startIndex ; i<nums.size() ; i++){
            if((temp.empty() || nums[i] >= temp.back()) && s.find(nums[i]) == s.end()) {
                temp.push_back(nums[i]);
                dfs(nums,temp,i+1);
                temp.pop_back();
                s.insert(nums[i]);
            }            
        }
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        dfs(nums,temp,0);
        return ans;
    }
};
