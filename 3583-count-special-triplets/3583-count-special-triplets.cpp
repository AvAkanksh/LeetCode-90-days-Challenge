class Solution {
public:
long long nCr(int n, int r) {
    if (r > n) return 0;
    r = std::min(r, n - r);    // nCr == nC(n-r)
    int MOD = 1e9+7;
    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result = (result * (n - r + i) / i);
    }
    return result%MOD;
}

    int specialTriplets(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            mp[nums[i]].push_back(i);
        }
        // for(auto x : mp){
        //     cout<<x.first<<": ";
        //     for(auto y : x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        int MOD = 1e9+7;
        long long ans = 0;
        for(auto x : mp){
            int middle = x.first;
            if(middle==0){
                ans+= nCr(x.second.size(),3);
            }else{

                int ends = middle*2;
                // cout<<"middle : "<<middle<<endl;
                // cout<<"ends : "<<ends<<endl;
                if(mp.find(ends)!=mp.end()){
                    for(auto y : x.second){
                        int size = mp[ends].size();
                        // cout<<"size:"<<size<<endl;
                        // cout<<"y: "<<y<<endl;
                        int idx = lower_bound(mp[ends].begin(), mp[ends].end(),y)-mp[ends].begin();
                        // cout<<"idx:"<<idx<<endl;

                        ans += (idx)*(size - idx) ;
                        ans = ans%MOD;
                    }
                }
            }
        }
        return ans;
        // return 0;
    }
};