class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int  n = matches.size();
        set<int> w;
        set<int> l;
        unordered_map<int,int> lcount;
        for(int i = 0 ; i<n ; i++){
            vector<int> curr = matches[i];
            w.insert(curr[0]);
            l.insert(curr[1]);
            lcount[curr[1]]++;
        }
        vector<vector<int>> ans;
        vector<int> ans0;
        vector<int> ans1;
        for(auto i = w.begin() ; i!=w.end() ; i++){
            if(l.find(*i)==l.end()){
                ans0.push_back(*i);
            }
        }

        for(auto i = l.begin() ; i!=l.end() ; i++){
            if(lcount[*i]==1){
                ans1.push_back(*i);
            }
        }
        ans.push_back(ans0);
        ans.push_back(ans1);
        return ans;
    }
};