class Solution {
public:
    void helper(vector<vector<char>> &grid , int i , int j, int &rows ,int &cols,vector<int> &dr ,  vector<int> &dc){
        if(i<0 || j<0 || i==rows || j == cols || grid[i][j]=='0'){return ;}
        grid[i][j]='0';
        for(int x = 0 ; x < 4; x++){
            helper(grid,i+dr[x] , j+dc[x] , rows,cols, dr, dc);
        }
        return;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0 ;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        for(int i = 0 ; i<rows ; i++){
            for(int j = 0 ; j<cols ; j++){
                if(grid[i][j]=='1'){
                    count++;
                    helper(grid,i,j,rows,cols,dr,dc);
                }
            }
        }
        return count;
    }
};