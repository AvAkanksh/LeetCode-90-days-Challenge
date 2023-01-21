class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.size();
        if(n>12){
            return ans;
        }
        string temp;
        for(int i = 1 ; i<=3 ; i++){
            for(int j = 1 ; j<=3 ; j++){
                for(int k = 1 ; k<=3 ; k++){
                    for(int l = 1 ; l<=3 ; l++){
                        if(i+j+k+l == s.size()){
                            int s1 = stoi(s.substr(0,i));
                            int s2 = stoi(s.substr(i,j));
                            int s3 = stoi(s.substr(i+j,k));
                            int s4 = stoi(s.substr(i+j+k,l));
                            if(s1<=255&&s2<=255&&s3<=255&&s4<=255){
                                if((temp=to_string(s1)+"."+to_string(s2)+"."+to_string(s3)+"."+to_string(s4)).length()==s.size()+3){
                                    ans.push_back(temp);
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};