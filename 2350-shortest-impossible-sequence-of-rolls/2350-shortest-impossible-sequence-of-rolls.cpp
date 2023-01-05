class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 0;
        int count = 0;
        unordered_map<int,int> m;
        for(auto r : rolls){
            m[r]++;
            if(m[r]==1){count++;}
            if(count==k){
                count=0;
                m.clear();
                ans++;
            }
        }
        
        return ans+1;
    }
};