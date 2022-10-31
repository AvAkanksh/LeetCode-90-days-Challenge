class Solution {
public:
    int fibhelp(int n ,vector<int> &t){
        if(t[n]!=-1){
            return t[n];
        }
        if(n <2){
            t[n] = n;
            return t[n];
        }
        
        t[n] = fibhelp(n-1,t) + fibhelp(n-2,t);
        return t[n];
    }
    
    int fib(int n) {
        vector<int> t (n+1,-1);
        return fibhelp(n,t);

    }
};