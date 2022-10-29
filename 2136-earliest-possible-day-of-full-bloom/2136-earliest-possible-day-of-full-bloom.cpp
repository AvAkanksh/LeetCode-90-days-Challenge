bool comp(pair<int,int> &x ,pair<int,int> &y){
    return x.second>y.second;
}
class Solution {
public:   
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> vec;
        for(int i = 0 ; i<n; i++){
            vec.push_back({plantTime[i],growTime[i]});
        }
        sort(vec.begin(),vec.end(),comp);
        int myplantTime = 0;
        int ans = 0;
        for(int i = 0 ; i<n; i++){
            myplantTime += vec[i].first;
            ans = max(ans,myplantTime+vec[i].second);
        }
        return ans;
    }
};