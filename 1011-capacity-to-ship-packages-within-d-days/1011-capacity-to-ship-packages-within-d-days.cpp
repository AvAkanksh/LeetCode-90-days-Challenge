class Solution {
public:
    bool check(int mid, vector<int>& weights, int days){
        int d = 0;
        int w = 0;
        for(int i = 0 ; i<weights.size() ; i++){
            if(w+weights[i]<=mid){
                w+=weights[i];
            }else{
                d++;
                w = weights[i];
            }
        }
        if(w>0){
            d++;
        }
        // int d = 0;
        // int w = 0;
        // for(auto x : weights){
        //     w+=x;
        //     if(w==mid){
        //         d++;
        //         w = 0;
        //     }
        //     if(w>mid){
        //         d++;
        //         w = x;
        //     }
        // }
        // if(w>0){d++;}
        cout<<d<<endl;
        cout<<"--"<<endl;
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = weights[0];
        for(auto x : weights){l = max(l,x);}
        int h = accumulate(weights.begin(), weights.end(), 0);
        // cout<<l<<endl;
        // cout<<h<<endl;
        int ans = h;
        while(l<=h){
            int mid = (h+l)/2;
            cout<<"l: "<<l<<" h :"<<h<<" mid : "<<mid<<endl;
            if(check(mid,weights,days)){
                ans = min(ans,mid);
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};