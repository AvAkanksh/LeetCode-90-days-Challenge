class MyQueue {
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int ans = output.top();
            output.pop();
            return ans;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int ans = output.top();
            output.pop();
            return ans;
        }
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
        
    }
    
    bool empty() {
        return (input.size()==0)&&(output.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */