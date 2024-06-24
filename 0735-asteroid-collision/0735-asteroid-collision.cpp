class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i = 0 ; i<asteroids.size() ; i++){
            int flag = true;
            while(s.size()>0 and asteroids[i]<0 and s.top()>0){
                if(s.top()+asteroids[i]<0){
                    s.pop();
                }else if( s.top()+asteroids[i]==0){
                    s.pop();
                    flag = false;
                    break;
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                s.push(asteroids[i]);
            }
        }
        int n = s.size();
        vector<int> ans(n,-1);
        for(int i = n-1 ; i>=0 ; i--){
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};