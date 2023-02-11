class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {    
        vector<int> ans(n,-1);
        // ans[0] = 0;
        // {{currentPosition,distance},color} 
        // red = 0;
        // blue = 1;
        vector<vector<int>> redAdjList(n);
        for(auto x: redEdges){
            redAdjList[x[0]].push_back(x[1]);
        }
        vector<vector<int>> blueAdjList(n);
        for(auto x: blueEdges){
            blueAdjList[x[0]].push_back(x[1]);
        }
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},-1});
        vector<bool> visb(n,false);
        vector<bool> visr(n,false);
        visr[0]=true;
        visb[0]=true;
        while(!q.empty()){
            pair<pair<int,int>,int> curr = q.front();
            q.pop();
            if(ans[curr.first.first]==-1){ans[curr.first.first]=curr.first.second;}
            if(curr.second!=1){
                for(auto &x : blueAdjList[curr.first.first] ){
                    if(!visb[x]){
                        visb[x]=true;        
                        q.push({{x,curr.first.second+1},1});
                    }
                }
            }
            if(curr.second!=0){
                for(auto &x : redAdjList[curr.first.first] ){
                    if(!visr[x]){
                        visr[x]=true;
                        q.push({{x,curr.first.second+1},0});
                    }
                }
            }
        }
        return ans;
        
    }
};