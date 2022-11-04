class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss;
        stack<char> ts;
        
        for(auto x : s){
            if(x=='#'){
                if(ss.size()>0){                
                    ss.pop();
                }
            }
            else{
                ss.push(x);
            }
        }
        for(auto x : t){
            if(x=='#'){
                if(ts.size()>0){                
                    ts.pop();
                }
            }
            else{
                ts.push(x);
            }
        }
        return (ts==ss);        
    }
};