class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        int n = s.size();
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        for (int i = 0 ; i<n/2 ; i++){
            if(st.find(s[i])!=st.end()){
                count++;
            }
        }
        // cout<<count<<endl;
        for(int i = n/2 ; i<n ; i++){
            if(st.find(s[i])!=st.end()){
                count--;
            }
        }
        return count==0;
    }
    
};