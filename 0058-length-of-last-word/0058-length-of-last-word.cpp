class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0;
        bool flag = false;
        for(int i = n-1 ;i>=0 ; i--){
            if(s[i]==' '&&flag){
                break;
            }
            else{
                if(s[i]!=' '){
                    flag = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};