class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>m;
        for(auto tasklen: tasks){
            m[tasklen]++;
        }
        int count = 0;
        for(auto x : m){
            cout<<x.first<<" "<<x.second<<endl;
            if(x.second!=1){
                count+=ceil((float)x.second/3.0);
                
            }
            else{return -1;}
        }
        return count;
    }
};