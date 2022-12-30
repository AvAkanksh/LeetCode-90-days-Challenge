class Solution {
public:
    void dfs(int source, int curr,int target, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>>&ans){
        if(curr==target){
            ans.push_back(path);
        }
        for(int i = 0 ; i<graph[curr].size() ; i++){
            path.push_back(graph[curr][i]);
            dfs(source,graph[curr][i],target,graph,path,ans);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int source = 0;
        int target = graph.size()-1;
        vector<int> path;
        path.push_back(0);
        for(int i = 0 ; i<graph[0].size() ; i++){
            path.push_back(graph[0][i]);
            dfs(source,graph[0][i],target,graph,path,ans);
            path.pop_back();
        }
        return ans;
    }
};