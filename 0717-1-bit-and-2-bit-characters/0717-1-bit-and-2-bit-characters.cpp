class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        bool isOneBit = true;
        for(int i = 0 ; i<n ; i++){
            if(bits[i]==1){
                isOneBit = false;
                i++;
            }else{
                isOneBit = true;
            }
        }
        return isOneBit;
    }
};