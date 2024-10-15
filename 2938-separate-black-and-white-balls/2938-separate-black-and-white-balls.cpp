class Solution {
public:
    long long minimumSteps(string s) {
        long long i =0;
        long long j = s.length()-1;
        long long count = 0;
        while(i<j){
            while(i<s.length() && s[i]!='1'){
                i++;
            }
            while(j>=0 && s[j]!='0'){
                j--;
            }
            if(i>j|| s[i]!='1' || s[j]!='0'){
                break;
            }
            // swap(s[i],s[j]);
            count+=(j-i);
            i++;
            j--;
        }
        return count;
    }
};