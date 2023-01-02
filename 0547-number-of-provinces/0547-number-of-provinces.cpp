class Solution {
public:
    void dfs(int node , vector<int> &vis, vector<vector<int>> &adj ){
        vis[node]=1;
        for(int i = 0 ; i<adj[node].size() ;i++){
            if(vis[adj[node][i]]!=1){
                dfs(adj[node][i],vis,adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj (n);
        for(int i = 0 ; i< isConnected.size() ; i++){
            for(int j = 0 ; j< isConnected[0].size() ; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int ans = 0;
        for(int i = 0 ; i< n ; i++ ){
            if(vis[i]!=1){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};