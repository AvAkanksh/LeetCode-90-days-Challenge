class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return true;
        }
        int count = 0;
        for(int i = 1 ; i<n ;i++){
            if(arr[i]<arr[i-1]){
                count++;
            }
        }
        return count == 0  || ((count ==1) && arr[0]>=arr[n-1]); 
    }
};