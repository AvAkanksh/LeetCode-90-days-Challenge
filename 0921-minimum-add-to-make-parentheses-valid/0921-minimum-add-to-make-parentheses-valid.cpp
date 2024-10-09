class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> st;
        for(char &ch : s){
            if(!st.empty() && st.top()=='(' and ch==')'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return st.size();
    }
};