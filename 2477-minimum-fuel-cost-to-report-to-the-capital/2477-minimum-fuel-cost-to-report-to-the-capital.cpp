class Solution {
public:
    int dfs(int node , int parent ,vector<vector<int>>&adj, long long &ans,int &seats){
        int passengers = 0;
        for(auto child : adj[node]){
            if(child!=parent){
                passengers += dfs(child,node, adj, ans,seats);
            }
        }
        if(node>0){        
            ans+=((passengers+seats)/seats);
        }
        return passengers+1;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        int cities = n+1;
        vector<vector<int>> adj(cities);
        for(auto &x:roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        long long ans = 0;
        dfs(0,-1,adj,ans,seats);
        return ans;
    }
};