class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &board,vector<vector<int>> &vis, vector<int> &d , int &n, int &m){
        vis[r][c]=1;
        for(int i =0 ; i<4 ; i++){
            int nr = r+d[i];
            int nc = c+d[i+1];
            if(nr>=0 &&nc>=0 &&nr<n &&nc <m && board[nr][nc]==1 && vis[nr][nc]==0 ){
                dfs(nr,nc,board,vis,d,n,m);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int> d = {0,-1,0,1,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0 ; i<n ; i++){
            if(board[i][0]==1 && vis[i][0]==0){
                dfs(i,0,board, vis,d,n,m);
            }
            if(board[i][m-1]==1 && vis[i][m-1]==0){
                dfs(i,m-1,board,vis,d,n,m);
            }
        }
        for(int j = 0 ; j<m ; j++){
            if(board[0][j]==1 && vis[0][j]==0){
                dfs(0,j,board, vis,d,n,m);
            }
            if(board[n-1][j]==1 && vis[n-1][j]==0){
                dfs(n-1,j,board,vis,d,n,m);
            }
        }
        int ans =0;
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ;j<m ; j++){
                if(board[i][j]==1 && vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};