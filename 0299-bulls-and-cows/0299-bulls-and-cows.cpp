class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> fs(10,0);
        vector<int> fg(10,0);
        int n = secret.size();
        for(int i = 0 ; i<n ; i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                fs[secret[i]-'0']++;
                fg[guess[i]-'0']++;
            }
        }
        int cows = 0;
        for(int i = 0 ; i<10; i++){
            cows += min(fs[i],fg[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};