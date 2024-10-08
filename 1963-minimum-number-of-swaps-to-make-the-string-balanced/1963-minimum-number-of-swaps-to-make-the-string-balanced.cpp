class Solution {
public:    
    int minSwaps(string s) {
        // Solution 1 : Stack Solution
        // stack<char> st;
        // for(char &ch : s){
        //     if(ch=='['){
        //         st.push(ch);
        //     }
        //     else if(!st.empty()){
        //         st.pop();
        //     }
        // }
        // return (st.size()+1)/2;

        // Solution 2 : Optimal Solution
        int count = 0;
        for(char &ch : s){
            if(ch=='['){
                count++;
            }
            else if(count>0){
                count--;
            }
        }
        return (count+1)/2;

    }
};