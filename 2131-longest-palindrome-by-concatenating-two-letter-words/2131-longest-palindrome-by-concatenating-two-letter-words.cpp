class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map <string,int> mp;
        for(auto x : words){
            mp[x]++;
        }
        
        int count = 0;
        bool flag = false;
        for(auto x : mp){
            string s = x.first;
            string r = s;
            int freq = x.second;
            reverse(r.begin(),r.end());
            if(s==r){
                count += 4*(freq/2);
                if(freq%2==1){
                    flag = true;
                }
            }
            else{
                if(mp.count(r)){
                    count += 4*min(mp[r],mp[s]);
                    mp.erase(r);
                }
            }
        }
        if(flag){
            count+=2;
        }
        return count;
    }
};