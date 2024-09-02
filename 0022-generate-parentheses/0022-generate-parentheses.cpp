class Solution {
public:
    void helper(int open, int close,  string s, vector<string>&ans,int n){
        if( close == n){
            ans.push_back(s);
            return ;
        }
        if(open<n){
            helper(open+1,close,s+"(",ans,n);
        }
        if(close<n and open>close){
            helper(open,close+1,s+")", ans,n);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        int open = 1;
        int close = 0; 
        helper(open,close,"(",ans,n);
        return ans;
    }
};