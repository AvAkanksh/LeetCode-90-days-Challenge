class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2){
            return false;
        }
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(int i = 0 ; i<n1 ; i++){
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;
        }
        int matches = 0;
        for(int i = 0 ; i<26; i++){
            if(hash1[i]==hash2[i]){
                matches++;
            }
        }
        for(int i = 0 ; i<26 ; i++){
            cout<<hash2[i]<<'\t';
        }
        if(matches==26){return true;}
        for(int i = 1; i<=n2-n1; i++){
            hash2[s2[i+n1-1]-'a']++;
            hash2[s2[i-1]-'a']--;
            int count = 0;
            for(int i = 0 ; i<26 ; i++){
                if(hash1[i]==hash2[i]){
                    count++;
                }
            }
            
            if(count==26){
                return true;
            }
        }
        return false;
    }
};