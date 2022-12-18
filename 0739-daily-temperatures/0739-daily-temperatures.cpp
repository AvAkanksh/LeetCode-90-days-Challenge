class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> s;
        s.push(n-1);
        for(int i = n-2 ; i>=0 ; i--){
            int count = 0;
            while(!s.empty() && temperatures[i]>=temperatures[s.top()]){
                s.pop();
                count++;
            }
            if(s.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=s.top()-i;
            }
            s.push(i);
        }
        
        return ans;
    }
};