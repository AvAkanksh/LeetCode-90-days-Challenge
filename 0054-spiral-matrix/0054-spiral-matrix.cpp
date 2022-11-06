class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> ans;
            int t = 0 ;
            int b = rows-1;
            int l = 0 ;
            int r = cols-1;
            while(t<=b && l<=r){
                for(int i = l ; i<=r ; i++){
                    ans.push_back(matrix[t][i]);
                }
                t++;
                for(int j = t ; j<=b ; j++){
                    ans.push_back(matrix[j][r]);
                }
                r--;
                if(ans.size()==rows*cols){
                    break;
                }
                for(int i = r ; i>=l ; i--){
                    ans.push_back(matrix[b][i]);
                }
                b--;
                for(int j = b ; j>=t ; j--){
                    ans.push_back(matrix[j][l]);
                }
                l++;
            }       
            return ans;
        
    }
};