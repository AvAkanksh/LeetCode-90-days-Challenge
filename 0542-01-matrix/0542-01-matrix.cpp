class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> d = {0,-1,0,1,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            ans[r][c]=dis;
            q.pop();
            
            for(int i= 0 ;i<4 ; i++){
                int nr = r+d[i];
                int nc = c+d[i+1];
                if(nr>=0 && nc >=0 && nr<m && nc<n && vis[nr][nc]==0 && mat[nr][nc]!=0){
                    q.push({{nr,nc},dis+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return ans;
        
    }
};