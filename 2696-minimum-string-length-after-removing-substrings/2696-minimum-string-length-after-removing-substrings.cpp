class Solution {
public:
    
    int minLength(string s) {
        stack<char> st;
        for(int i = 0 ; s[i]!='\0' ; i++){
            if(!st.empty() && (st.top()=='A' || st.top()=='C') && st.top()+1==s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    
        return st.size();
    }
};