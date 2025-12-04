class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int ans = 0;
        for(auto x : directions){
            if(st.empty()==true){
                st.push(x);
            }else{
                char top = st.top();
                if(((top == 'R' and x=='S') || (top=='S' and x=='L') )){
                    ans+=1;
                    st.pop();
                    st.push('S');
                }else if(top=='R' and x=='L'){
                    ans+=2;
                    st.pop();
                    while(!st.empty() and st.top()=='R'){
                        ans++;
                        st.pop();
                    }
                    st.push('S');
                }else{
                    st.push(x);
                }
                
            }
        }
        return ans;
    }
};