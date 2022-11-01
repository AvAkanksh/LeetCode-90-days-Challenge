class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> myset;
        int n = s.size();
        while(l<n && r<n){
            if(myset.find(s[r])==myset.end()){
                myset.insert(s[r]);
                r++;
                ans = max(r-l,ans);
            }
            else{
                myset.erase(s[l]);
                l++;
            }
            
        }
        return ans;
    }
};