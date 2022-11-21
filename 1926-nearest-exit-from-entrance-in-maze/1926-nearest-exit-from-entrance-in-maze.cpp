class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int level = 0;
        maze[entrance[0]][entrance[1]]='+';
        int rows = maze.size();
        int cols = maze[0].size();
        vector<int> d = {0,-1,0,1,0};
        while(!q.empty()){
            int count = q.size();
            level++;
            for(int i = 0 ; i< count ; i++){
                auto curr = q.front();
                q.pop();
                for(int j = 0 ; j<4 ; j++){
                    int nr = curr.first + d[j];
                    int nc = curr.second + d[j+1];
                    if(nr <rows && nr>=0 && nc<cols && nc >=0 ){
                        if(maze[nr][nc]=='+'){continue;}
                        if(nc == 0 || nc == cols-1 || nr == 0 || nr == rows-1){
                            return level;
                        }
                        // cout<<nr<<" "<<nc<<endl;
                        maze[nr][nc] = '+';
                        q.push({nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};