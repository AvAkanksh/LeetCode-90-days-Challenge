class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>>suf(26);
        long long res=0;
        for(auto & idea :ideas){
            suf[idea[0]-'a'].insert(idea.substr(1));
        }
        for(int i=0;i<suf.size();i++){
            for(int j=0;j<suf.size();j++){
                if(i==j)continue;
                int same=0;
                for(auto & s :suf[i]){
                    if(suf[j].count(s))same++;
                }
                int dist1=suf[i].size()-same;
                int dist2=suf[j].size()-same;
                res+=dist1*dist2;
            }
        }
        return res;
    }
};