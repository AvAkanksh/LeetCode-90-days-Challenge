class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> &board,vector<vector<int>> &vis, vector<int> &d , int &n, int &m){
        vis[r][c]=1;
        for(int i =0 ; i<4 ; i++){
            int nr = r+d[i];
            int nc = c+d[i+1];
            if(nr>=0 &&nc>=0 &&nr<n &&nc <m && board[nr][nc]=='O' && vis[nr][nc]==0 ){
                dfs(nr,nc,board,vis,d,n,m);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int> d = {0,-1,0,1,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0 ; i<n ; i++){
            if(board[i][0]=='O'&&vis[i][0]==0){
                dfs(i,0,board, vis,d,n,m);
            }
            if(board[i][m-1]=='O'&&vis[i][m-1]==0){
                dfs(i,m-1,board,vis,d,n,m);
            }
        }
        for(int j = 0 ; j<m ; j++){
            if(board[0][j]=='O'&&vis[0][j]==0){
                dfs(0,j,board, vis,d,n,m);
            }
            if(board[n-1][j]=='O'&&vis[n-1][j]==0){
                dfs(n-1,j,board,vis,d,n,m);
            }
        }
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ;j<m ; j++){
                if(board[i][j]=='O'&&vis[i][j]==0){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};