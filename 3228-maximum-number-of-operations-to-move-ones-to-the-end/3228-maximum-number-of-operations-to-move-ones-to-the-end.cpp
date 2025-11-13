class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int n = s.size();
        for(int i = 1 ; i<n ;i++){
            if(s[i-1]!=s[i]){
                ans++;
            }
        }
        return s[0]=='0'?ans-1:ans;
    }
};