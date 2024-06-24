class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i = 0 ; i<asteroids.size() ; i++){
            while(s.size()>0 and asteroids[i]<0 and s.top()>0){
                if(s.top()+asteroids[i]<0){
                    s.pop();
                }else if( s.top()+asteroids[i]==0){
                    s.pop();
                    asteroids[i] = 0;
                }else{
                    asteroids[i]= 0;
                }
            }
            if(asteroids[i]){
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