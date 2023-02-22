class Solution {
public:
    bool isPossible(int mid, vector<int>& weights, int &days){
        int sum = 0 ;
        int daysRequired = 1;
        for(int i = 0 ; i<weights.size() ;i++){
            sum+=weights[i];
            if(sum>mid){
                daysRequired++;
                sum = weights[i];
            }
        }
        return (daysRequired<=days);
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
        int high=0;
        for(auto weight : weights){
            low = max(low,weight);
            high += weight;
        }
        int mid;
        int ans;
        while(low<=high){
            mid = low+(high - low)/2;
            if(isPossible(mid,weights,days)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        return ans;
    }
};