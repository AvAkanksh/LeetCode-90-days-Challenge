class Solution {
public:    
    int minSwaps(string s) {
        stack<char> st;
        for(int i = 0 ; i<s.size() ; i++){
            if(!st.empty() && st.top() == '[' and s[i]==']'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            return 0;
        }
        return (st.size()/2+1)/2;
    }
};