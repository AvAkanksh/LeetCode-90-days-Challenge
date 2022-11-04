class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int n = s.size();
        int r = n-1;
        unordered_set<char> mySet = {'a','e','i','o','u','A','E','I','O','U'};
        while(l<r){
            while(mySet.find(s[l])==mySet.end() && l<n){
                l++;
            }
            while(mySet.find(s[r])==mySet.end() && r>0){
                r--;
            }
            if(l>r){
                break;
            }
            // cout<<l<<s[l]<<" "<<r<<s[r]<<endl;
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
            
        }
        return s;
    }
};