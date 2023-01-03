class Solution {
    vector<int> adj[100001];
public:
    int dfs(int curr, vector<int> &informTime){
        int maxTime = 0;
        for(int i = 0 ; i<adj[curr].size() ; i++){
            maxTime = max(maxTime,dfs(adj[curr][i],informTime));
        }
        return informTime[curr]+maxTime;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i = 0 ; i<n;i++){
            if(manager[i]!=-1){            
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }
};