class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0 ; i<points.size() ;i++){
            int samePoint =1;
            unordered_map<double,int> mp;
            for(int j = i+1 ; j <points.size() ; j++){
                if(points[i][0]==points[j][0]&& points[i][1]==points[j][1]){
                    samePoint++;
                }
                else if(points[i][0]==points[j][0]){
                    mp[INT_MAX]++;
                }
                else{
                    double slope = double(points[i][1]-points[j][1])/double(points[i][0]-points[j][0]);
                    mp[slope]++;
                }
            }
            int localMax = 0;
            for(auto x : mp){
                localMax = max(x.second,localMax);
            }
            localMax+=samePoint;
            ans = max(ans,localMax);
        }
        return ans;
    }
};