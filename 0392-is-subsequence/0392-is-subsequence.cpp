class Solution {
public:
    bool isSubsequence(string s, string t) {
        stack<char> mystack;
        for(auto x : s){
            mystack.push(x);
        }
        int i = t.size()-1;
        while(!mystack.empty() && i>=0 ){
            if(t[i]==mystack.top()){
                mystack.pop();
            }
            i--;
        }
        if(!mystack.empty()){return false;}
        return true;
    }
};