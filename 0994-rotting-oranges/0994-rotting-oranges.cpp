class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh_count = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0  ; j<m ; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1){
                    fresh_count++;
                }
            }
        }
        int tmax = 0;

        vector<int> d = {0,-1,0,1,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tmax = max(tmax,t);
            q.pop();
            cout<<r<<" "<<c<<endl;
            for(int i = 0 ; i< 4 ; i++){
                int nx = r+d[i];
                int ny = c+d[i+1];
                if(nx>=0 && ny>=0 && nx<n &&ny <m && grid[nx][ny]==1){
                    fresh_count--;
                    grid[nx][ny] = 2;
                    q.push({{nx,ny},t+1});
                }
            }
        }

        return fresh_count==0?tmax:-1;
    }
};