class Solution {
public:
    void dfs(vector<vector<int>> &image , int sr , int sc,int &val, int &color,int &rows , int &cols){
        
        if(image[sr][sc]==val){
            image[sr][sc] = color;
        }
        
        vector<int> dr = {-1 , 0 , 1 , 0 };
        vector<int> dc = { 0 , 1 , 0 , -1};
        
        for(int i = 0 ; i<4 ; i++){
            int nr = sr+dr[i];
            int nc = sc+dc[i];
            if(nr<rows && nr>=0 && nc<cols && nc>=0 && image[nr][nc]==val){
                dfs(image,nr,nc,val,color,rows,cols);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        int rows = image.size();
        int cols = image[0].size();
        if(val == color){
            return image;
        }
        dfs(image,sr, sc, val,color,rows, cols);
        
        return image;
        
    }
};