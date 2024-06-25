class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k){
            return "0";
        }
        stack<char> s;
        int n = num.size();
        for(int i = 0 ; i<n ; i++){
            while(s.size()>0 and (s.top()-'0')>(num[i]-'0') and k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        
        while(k>0){
            s.pop();
            k--;
        }
        
        string ans;
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        string finalAns;
        bool flag = true;
        
        for(int i = 0 ; i<ans.size() ; i++){
            if(ans[i]=='0' and flag){
                continue;
            }else{
                finalAns.push_back(ans[i]);
                flag = false;
            }
        }
        return finalAns==""?"0":finalAns;
        
        
    }
};