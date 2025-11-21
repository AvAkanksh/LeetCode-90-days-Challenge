class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // vector<string> unique_palindromes;
        // string alphabets = "abcdefghijklmnopqrstuvwxyz";
        // int n = alphabets.size();
        // for(int i =0 ; i<n ; i++){
        //     for(int j = 0 ; j<n ; j++){
        //         string temp = "" ;
        //         temp+= alphabets[i];
        //         temp+=alphabets[j];
        //         temp+=alphabets[i];
        //         // string temp = to_string(alphabets[i])+to_string(alphabets[j])+to_string(alphabets[i]);
        //         unique_palindromes.push_back(temp);
        //         cout<<temp<<endl;
        //     }
        // }
        unordered_map<char,pair<int,int>> mp;
        int n = s.size();
        for(int i =0 ; i<n ; i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = {i,-1};
            }else{
                mp[s[i]].second = i;
            }
        }
        int ans = 0;
        for(auto x : mp){
            int start = x.second.first;
            int end = x.second.second;
            if(end!=-1){
                unordered_set<char> st;
                for(int i = start+1 ; i<end ; i++){
                    st.insert(s[i]);
                }
                ans+=st.size();
            }
        }
        return ans;
    }
};