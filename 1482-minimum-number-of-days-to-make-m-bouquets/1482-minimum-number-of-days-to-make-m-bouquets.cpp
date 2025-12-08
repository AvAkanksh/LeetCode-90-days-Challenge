class Solution {
public:
    bool check(int mid, vector<int>& bloomDay, int m, int k){
        int ans = 0;
        int count = 0;
        for(auto x : bloomDay){
            if(x<=mid){
                count++;
            }else{
                ans+=int(count/k);
                count=0;
            }
        }
        // cout<<"count"<<count<<endl;
        // cout<<"k"<<k<<endl;
        ans += count/k;
        // cout<<"ans"<<ans<<endl;
        // if(count>0){
        //     ans+= int(count/k);
        // }
        return ans>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        set<int> s(bloomDay.begin(), bloomDay.end());
        vector<int> v (s.begin(),s.end());
        int n = v.size();
        int l = 0;
        int h = n-1;
        int ans = INT_MAX;
        while(l<=h){
            int mid = ((h+l)/2);
            int mid_val = v[mid];
            cout<<mid<<endl;
            if(mid<n and check(mid_val, bloomDay,m, k)){
                ans = min(ans,mid_val);
                h = mid-1;
            }else{
                l = mid+1;
            }
            // cout<<"low"<<l<<endl;
            // cout<<"high"<<h<<endl;
            // cout<<"mid"<<mid<<endl;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};