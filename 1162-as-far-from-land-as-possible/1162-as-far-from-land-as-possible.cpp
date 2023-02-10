class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ans = -1;
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        bool landFlag = false;
        bool waterFlag = false;
        vector<vector<int>> visited(n,vector<int>(n,0));
        for(int i = 0 ; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j] = 1;
                    landFlag = true;
                }
                if(grid[i][j]==0){
                    waterFlag = true;
                }
            }
        }
        if(!waterFlag||!landFlag){
            return ans;
        }

        vector<int> d = {0,-1,0,1,0};
        while(!q.empty()){
            int count = q.size();
            for(int i = 0 ; i<count ; i++){
                pair<int,int> curr = q.front();
                q.pop();
                for(int i = 0 ; i<4 ; i++){
                    int nr = curr.first+d[i];
                    int nc = curr.second+d[i+1];
                    if(nc>=0 && nr>=0 && nc<m&&nr<n && grid[nr][nc]==0&&visited[nr][nc]==0){
                        q.push({nr,nc});
                        visited[nr][nc]=1;
                    }
                }
            }
            ans++;

        }
        return ans;
        
    }
};