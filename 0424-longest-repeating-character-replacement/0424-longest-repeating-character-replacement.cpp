class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int ans = 0;
        int len;
        int maxf=INT_MIN;
        int n = s.size();
        vector<int> vec(26,0);
        for(int i = 0 ; i<n ; i++){
            len = i-l+1;
            vec[s[i]-'A']++;
            maxf = max(maxf , vec[s[i]-'A']);
            if(len-maxf<=k){
                ans = len;
            }
            else{
                while(len-maxf>k && l<=i){
                    vec[s[l]-'A']--;
                    l++;
                    len = i-l+1;
                }
            }
            ans = max(ans,len);
        }
        return ans;
    }
};