class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        vector<vector<int>> adj(n);
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        unordered_set<int> s;
        queue<int> q;
        q.push(source);
        s.insert(source);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto x : adj[curr] ){
                if(x==destination){
                    return true;
                }
                else{
                    if(s.find(x)==s.end()){
                        q.push(x);
                        s.insert(x);
                    }
                }
            }
        }
        return false;
    }
};