class Solution {
public:
    int dfs(int curr,int parent, vector<vector<int>> &adj, vector<bool>&hasApple){
        int time = 0;
        for(auto child : adj[curr]){
            if(child!=parent){
                int childTime = dfs(child,curr,adj,hasApple);
                if(childTime!=0 || hasApple[child]){
                    time+= 2+childTime;
                }
            }
        }
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};