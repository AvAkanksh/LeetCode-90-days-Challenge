class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,string> m;
        int j = 0;
        int wordCount =0;
        for(int i = 0 ; i<pattern.size(); i++){
            string word = "";
            while(j<s.size()&& s[j]!=' '){
                word += s[j];
                j++;
            }
            j++;
            wordCount++;
            cout<<j<<endl;
            cout<<word<<endl;

            string p = to_string(pattern[i]);
            if(m.find(p)==m.end() && m.find(word)==m.end()){
                m[p]= word;
                m[word] = p;
            }
            else{
                if(m[p]!=word || m[word]!=p){
                    return false;
                }   
            }
        }
                  return pattern.size()==wordCount && j-1==s.size();
    }
};