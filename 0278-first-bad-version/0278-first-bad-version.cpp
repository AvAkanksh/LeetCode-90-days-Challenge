// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1 ;
        int h = n;
        if(n==1){
            return n;
        }
        while(l<=h){
            int mid =  l + (h-l)/2;
            if(isBadVersion(mid) && !isBadVersion(mid-1)){
                return mid;
            }
            else{
                if(!isBadVersion(mid)){
                    l = mid+1;
                }
                else{
                    h = mid;
                }
            }
        }
        return -1;
        
    }
};