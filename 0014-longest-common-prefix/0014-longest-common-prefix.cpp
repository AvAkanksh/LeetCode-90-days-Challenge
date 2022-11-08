class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0){
            return "";
        }
        string prefix = strs[0];
        for(int i = 1 ; i<n ; i++){
            string check = strs[i];
            while(check.find(prefix)!=0){
                prefix.pop_back();
            }
        }
        return prefix;
    }
};