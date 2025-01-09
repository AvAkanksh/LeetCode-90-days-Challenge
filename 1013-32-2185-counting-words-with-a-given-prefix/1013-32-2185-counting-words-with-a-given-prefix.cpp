class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int pref_len = pref.length();
        for(auto word : words){
            if(word.length()>= pref_len){
                if(word.substr(0,pref_len)==pref){
                    ans++;
                }
            }
        }
        return ans;
    }
};