class Solution {
public:
    int help(int n , vector<int> &t){
        if(t[n]!=-1){
            return t[n];
        }
        if(n<=2){
            t[n] = n;
            return t[n];
        }
        t[n] = help(n-1,t) + help(n-2,t);
        return t[n];
    }
    
    int climbStairs(int n) {
        vector<int> t(n+1,-1);
        return help(n,t);
    }
};