class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> phash(26,0);
        vector<int> whash(26,0);
        int n = p.size();
        int m = s.size();
        if(n>m){
            return ans;
        }
        for(int i = 0 ; i<n ; i++){
            phash[p[i]-'a']++;
            whash[s[i]-'a']++;
        }
        if(phash == whash){
            ans.push_back(0);
        }
        for(int i = n ; i<s.size() ; i++){
            whash[s[i]-'a']++;
            whash[s[i-n]-'a']--;
            if(whash==phash){
                ans.push_back(i-n+1);
            }
        }
        return ans;
        
    }
};