class Solution {
public:
    int maximumSwap(int num) {
        if(num<=10)return num;
        string digits = to_string(num);
        int n = digits.size();
        int max_val_idx = n-1;
        int swap_left = -1;
        int swap_right = n-1;
        for(int i = n-2 ; i>=0 ; i--){
            if(digits[max_val_idx]<digits[i]){
                max_val_idx = i;
            }else if(digits[max_val_idx]>digits[i]){
                swap_left = i;
                swap_right = max_val_idx;
            }
        }
        if(swap_left != -1){
            swap(digits[swap_left], digits[swap_right]);
        }
        return stoi(digits);
    }
};