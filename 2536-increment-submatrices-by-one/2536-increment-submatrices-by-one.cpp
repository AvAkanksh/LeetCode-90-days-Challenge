class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> v (n+1,vector<int>(n+1,0));
        for(auto q: queries){
            // auto [r1,c1,r2,c2] = queries[i];
            int r1 = q[0],c1 = q[1], r2 = q[2], c2 = q[3];
            v[r1][c1] += 1;
            v[r2+1][c1] += -1;
            v[r1][c2+1] += -1;
            v[r2+1][c2+1] += 1; 
        }
        vector<vector<int>> ans (n,vector<int>(n,0));
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i==0 and j==0){
                    ans[i][j] = v[i][j];
                }else if(i==0 and j!=0){
                    ans[i][j] = ans[i][j-1] + v[i][j];
                }else if(j==0 and i!=0){
                    ans[i][j] = ans[i-1][j] + v[i][j];
                }
                else{
                    ans[i][j] = ans[i-1][j]+ans[i][j-1] + v[i][j] - ans[i-1][j-1];
                }
            }
        }
        return ans;
    }
};