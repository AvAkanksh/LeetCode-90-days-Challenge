class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m);
        for(int b = 0 ; b < m ; b++){
            int curr_pos = b;
            int next_pos;
            for(int i = 0 ; i < n ; i++){
                next_pos = curr_pos + grid[i][curr_pos];
                if(next_pos<0 || next_pos==m || grid[i][curr_pos] != grid[i][next_pos]){
                    curr_pos = -1;
                    break;
                }
                curr_pos = next_pos;
            }
            ans[b] = curr_pos;
        }
        return ans;
    }
};