class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        for(int i = 0 ; i<asteroids.size() ; i++){
            int flag = true;
            cout<<"hi : "<<asteroids[i]<<endl;
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
            cout<<"flag : "<<flag<<endl;
            if(flag){
                s.push(asteroids[i]);
            }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};