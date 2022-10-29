class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        myStack.push('#');
        for(auto x:s){
            if(x=='(' || x=='[' || x=='{'){
                myStack.push(x);
            }
            else{
                char top = myStack.top();
                if(top=='(' && x==')' || top=='[' && x==']' || top=='{' && x=='}'){
                    myStack.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(myStack.top()=='#'){
            return true;   
        }
        return false;
    }
};