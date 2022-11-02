class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set <string> myBank(bank.begin(),bank.end());
        unordered_set<string> visited;
        queue<pair<string,int>> q;
        q.push({start,0});
        visited.insert(start);
        vector<char> c = {'A','C','G','T'};
        while(!q.empty()){
            string s = q.front().first;
            int level = q.front().second;
            if(s==end){
                return level;
            }
            q.pop();
            string new_gene ;
            for(int i = 0 ; i<8 ; i++){
                for (auto x : c){
                    new_gene = s.substr(0,i) + x + s.substr(i+1);
                    if(myBank.find(new_gene)!=myBank.end() && visited.find(new_gene)==visited.end()){
                        q.push({new_gene,level+1});
                        visited.insert(new_gene);
                    }
                }
            }
        }
        return -1;
    }
};