class Solution {
public:
    bool isSubsequence(string s, string t) {

        for(int i = t.size()-1 ; i>=0 && !s.empty(); i--){
            if(t[i]==s[s.size()-1]){s.pop_back();}
        }
        return s.empty();
    }
};