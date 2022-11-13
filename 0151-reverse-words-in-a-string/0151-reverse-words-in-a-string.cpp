class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = n-1;
        while(i>=0){
            while(i>=0 && s[i]==' '){
                i--;
            }
            int j = i;
            while(j >=0  && s[j]!=' ' ){
                j--;
            }
            string sub = s.substr(j+1,i-j);
            if(sub==""){
                continue;
            }
            if(ans ==""){
                ans = sub;
            }
            else{
                ans = ans+" "+sub;
            }
            i= j-1;
        }
        // if(ans[ans.size()-1]==' '){
        //     ans.resize(ans.size()-1);
        // }
        return ans;
    }
};