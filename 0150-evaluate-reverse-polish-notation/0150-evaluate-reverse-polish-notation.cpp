class Solution {
public:
    long int evalRPN(vector<string>& tokens) {
        stack<long int> s;
        for(int i = 0 ; i<tokens.size() ;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                long int a = s.top();
                s.pop();
                long int b = s.top();
                s.pop();
                if(tokens[i]=="+"){
                    s.push(a+b);
                }
                if(tokens[i]=="-"){
                    s.push((b-a));
                }
                if(tokens[i]=="*"){
                    s.push((a*b));
                }
                if(tokens[i]=="/"){
                    s.push((b/a));
                }
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};