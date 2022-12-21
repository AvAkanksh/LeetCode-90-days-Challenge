class Solution {
public:
    bool checkbipartite(int src, vector<int> &color, vector<vector<int>>&adj ){
        color[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int currColor = color[curr];
            for(auto x: adj[curr]){

                if(color[x]!=-1){
                    if(color[x]==currColor){return false;}
                }
                else{
                    color[x] = (currColor==0)?1:0;
                    q.push(x);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto x: dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> color(n+1,-1);
        for(int i = 1 ; i<=n ; i++){
            if(color[i]==-1){
                if(checkbipartite(i,color,adj)==false){return false;}
            }
        }
        return true;
    }
};