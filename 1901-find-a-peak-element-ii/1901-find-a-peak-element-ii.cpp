class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0 ;
        int high = n-1;

        while(low<=high){
            int mid = (low+high)/2;
            int max_ele_col = INT_MIN ;
            int max_ele_row = INT_MIN;
            int maxEle = INT_MIN;
            cout<<"low:"<<low<<endl;
            cout<<"high:"<<high<<endl;
            for(int i = -1 ; i<=1 ; i++){
                if(mid+i>=0 and mid+i<n){
                    for(int j = 0 ; j<m ; j++){
                        if(maxEle<mat[j][mid+i]){
                            max_ele_col = i;
                            max_ele_row = j;
                            maxEle = mat[j][mid+i];
                        }
                    }
                }
            }
            if(max_ele_col==0){
                return {max_ele_row,mid};
            }else if(max_ele_col==1){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return {-1,-1};
    }
};