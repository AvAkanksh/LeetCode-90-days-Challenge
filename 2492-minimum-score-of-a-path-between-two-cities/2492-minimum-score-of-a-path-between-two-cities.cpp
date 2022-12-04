class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto r : roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        queue<int> q;
        q.push(1);
        vector<int> visited(n+1,0);
        visited[1] = 1;
        int ans = INT_MAX;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto x : adj[curr]){
                if(!visited[x.first]){
                    q.push(x.first);
                    visited[x.first] = 1;
                }
            }
        }
        for(auto r : roads){
            if(visited[r[0]]&&visited[r[1]]){
                ans = min(ans,r[2]);
            }
        }
        return ans;
    }
};