class Solution {
public:
    void dfs(int i , int j , vector<vector<char>> &grid,vector<int> &d){
        if(i<0 || j<0 || i==grid.size() || j== grid[0].size() || grid[i][j]=='0'){return;}
        grid[i][j]='0';
        for(int x = 0 ; x<4 ; x++){
            dfs(i+d[x],j+d[x+1],grid,d);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<int>d = {0,-1,0,1,0};
        for(int i = 0 ; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid,d);
                }
            }
        }
        return ans;
    }
};