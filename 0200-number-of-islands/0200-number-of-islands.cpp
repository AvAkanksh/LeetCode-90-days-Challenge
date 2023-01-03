class Solution {
public:
    void dfs(int i , int j , vector<vector<char>> &grid){
        grid[i][j]='2';
        vector<int>d = {0,-1,0,1,0};
        for(int x = 0 ; x<4 ; x++){
            int nx = i+d[x];
            int ny = j+d[x+1];
            
            if(nx>=0 && nx<grid.size() && ny>=0 &&ny<grid[0].size() && grid[nx][ny]=='1'){
                dfs(nx,ny,grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0 ; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};