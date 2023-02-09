class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char,unordered_set<string>> hash;
        for(auto &str : ideas){
            hash[str[0]].insert(str.substr(1));
        }
        long long ans = 0;
        for(auto &x : hash){
            for(auto &y : hash){
                if(x.first==y.first){continue;}
                int intersection = 0;
                for(auto &word : x.second){
                    if(y.second.count(word)){
                        intersection++;
                    }
                }
                ans += (x.second.size()-intersection)*(y.second.size()-intersection);
            }
        }
        return ans;
    }
};