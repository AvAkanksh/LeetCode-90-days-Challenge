class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int n = num.size()-1;
        int carry = 0;
        while(n>=0 || carry>0 ||k>0){
            int x = carry;
            if(n>=0){
                x+=num[n];
            }
            if(k>0){
                x+=k%10;
                k/=10;
            }
            ans.push_back(x%10);
            carry = x/10;
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};