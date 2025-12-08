class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0]>k){
            return k;
        }
        if(arr[arr.size()-1]-arr.size()<k){
            return k+arr.size();
        }
        int low = 0;
        int high = arr.size()-1;
        int idx = low;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] - mid-1<k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return k + high +1 ;
        // return arr[idx] + (k-(arr[idx]-idx-1));
        // unordered_map<int,int> freq;
        // for(auto x : arr){
        //     freq[x]++;
        // }
        // int count = 0;
        // for(int i = 1 ; i<=arr.size()+k ; i++){
        //     if(freq.find(i)==freq.end()){
        //         count++;
        //     }
        //     if(count==k){
        //         return i;
        //     }
        // }
        // return -1;
    }
};