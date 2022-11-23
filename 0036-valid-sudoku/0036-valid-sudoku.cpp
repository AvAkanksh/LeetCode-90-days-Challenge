class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                string r_string = to_string(board[i][j]) +" r-"+ to_string(i);
                string c_string = to_string(board[i][j]) +" c-"+ to_string(j);
                string b_string = to_string(board[i][j]) +" b-"+ to_string(i/3) + to_string(j/3);
                if(s.count(r_string) || s.count(c_string) || s.count(b_string)){
                    return false;
                }
                s.insert(r_string);
                s.insert(c_string);
                s.insert(b_string);
            }
        }
        return true;
    }
};