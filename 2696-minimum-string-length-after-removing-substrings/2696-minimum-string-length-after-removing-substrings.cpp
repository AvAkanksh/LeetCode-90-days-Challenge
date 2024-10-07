class Solution {
public:
    
    int minLength(string s) {
        // Solution 1
        // stack<char> st;
        // for(int i = 0 ; s[i]!='\0' ; i++){
        //     if(!st.empty() && (st.top()=='A' || st.top()=='C') && st.top()+1==s[i]){
        //         st.pop();
        //     }else{
        //         st.push(s[i]);
        //     }
        // }
        // return st.size();
        
        // Solution 2 : 2 Pointer Approach
        int writer = 0;
        int reader = 0;
        while(reader<s.size()){
            s[writer] = s[reader];
            if(writer > 0 && (s[writer]=='B'|| s[reader]=='D') && s[writer]==s[writer-1]+1){
                writer--;
            }
            else{
                writer++;
            }
            reader++;
        }
        return writer;
    }
};