class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for(auto x:s){
            if(x=='(' || x=='[' || x=='{'){
                myStack.push(x);
            }
            else{
                if(!myStack.empty()){
                    char top = myStack.top();
                    if(top=='(' && x==')' || top=='[' && x==']' || top=='{' && x=='}'){
                        myStack.pop();
                    }
                    else{
                        return false;
                        // break;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(myStack.empty()){
            return true;   
        }
        return false;
    }
};