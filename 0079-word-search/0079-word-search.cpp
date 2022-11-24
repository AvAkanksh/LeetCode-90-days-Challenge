class Solution {
public:
    bool helper( vector<vector<char>> &board,int i , int j , int k , string &word){
        if(k==word.size()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() ||word[k]!=board[i][j]){
            return false;
        }
        char c = board[i][j];
        board[i][j] = '.';
        bool ans = helper(board,i,j+1,k+1,word)|| helper(board,i,j-1,k+1,word)|| helper(board,i+1,j,k+1,word)|| helper(board,i-1,j,k+1,word);
        board[i][j] = c;
        return ans;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0 ; i< rows ; i++){
            for(int j = 0  ; j<cols ; j++){
                if(helper(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};