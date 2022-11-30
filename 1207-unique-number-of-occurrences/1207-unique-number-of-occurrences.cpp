class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto x : arr){
            m[x]++;
        }
        unordered_set<int> s;
        for(auto x = m.begin() ; x!= m.end() ; x++){
            if(s.find(x->second)!=s.end()){
                return false;
            }
            s.insert(x->second);
        }
        return true;
    }
};