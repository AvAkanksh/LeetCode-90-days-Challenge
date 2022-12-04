class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long s = accumulate(skill.begin(),skill.end(),0)*2/n;
        unordered_map<int,int> m;
        long long chemistry = 0;
        // cout<<"s:"<<s<<endl;
        for(auto x: skill){
            m[x]++;
        }
        for(auto [val,freq] : m){
            // cout<<val<<" "<<freq<<" "<<m.count(s-val)<<" "<<(s-val)<<endl;
            
            if(!m.count(s-val)||m[s-val]!=freq){
                // cout<<"Exiting"<<endl;
                return -1;
            }
            else{
                // cout<<"Adding"<<endl;
                chemistry += val*(s-val)*freq;
            }
        }
        return chemistry/2;
    }
};