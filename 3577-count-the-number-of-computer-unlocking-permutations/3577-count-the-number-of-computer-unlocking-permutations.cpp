class Solution {
public:
    long long factorial(int n){
        if(n<=1){
            return 1;
        }
        int MOD = 1e9+7;
        long long result = 1;
        for(int i =  2;i<=n ;i++){
            result = result*i;
            result = result%MOD;
        }
        return result;
    }
    int countPermutations(vector<int>& complexity) {
        int ans= 0;
        int rootComplexity = complexity[0];
        int n = complexity.size();
        for(int i = 1 ;i<n ; i++){
            if(complexity[i]<=rootComplexity){
                return 0;
            }
        }
        return factorial(n-1);
    }
};