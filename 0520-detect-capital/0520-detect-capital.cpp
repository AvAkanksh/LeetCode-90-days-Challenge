class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital_count = 0;
        bool first_capital = true;
        if(word.size()>=1){
            first_capital = word[0]<='Z' && word[0]>='A';
        }
        for(auto x : word){
            if(x<='Z' && x>='A'){
                capital_count++;
            }
        }
        return capital_count==1 && first_capital || capital_count==word.size() || capital_count==0;
    }
};