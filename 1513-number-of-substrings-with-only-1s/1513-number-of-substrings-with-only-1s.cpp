class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        int n = s.size();
        int count = 0;
        unordered_map<long long,long long> mp;
        for(int i = 0 ; i<n ; i++){
            if(s[i]=='1'){
                count++;
            }else{
                mp[count]++;
                count=0;
            }
            if(i==n-1 and s[i]=='1'){
                mp[count]++;
            }
        }
        for(auto x :mp){
            ans+=(x.first*(x.first+1))%(1e9+7/2*x.second;
        }
        return ans;
    }
};