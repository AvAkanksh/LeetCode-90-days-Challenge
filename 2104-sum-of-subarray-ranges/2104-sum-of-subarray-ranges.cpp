class Solution {
public:
    long long findSubarrayMinimas(vector<int> &nums){
        int n = nums.size();
        vector<long long> nsl(n,-1);
        vector<long long> nsr(n,n);
        stack<int> s;
        for(int i = 0 ; i<n ; i++){
            if(s.size()==0){
                nsl[i] = -1;
            }else if(s.size()>0 and nums[s.top()]<nums[i]){
                nsl[i] = s.top();
            }else if (s.size()>0 and nums[s.top()]>=nums[i]){
                while(s.size()>0 and nums[s.top()]>=nums[i]){
                    s.pop();
                }
                if(s.size()==0){
                    nsl[i] = -1;
                }else {
                    nsl[i] = s.top();
                }
            }
            s.push(i);
        }
        
        while(s.size()>0){
            s.pop();
        }
        
        for(int i = n-1 ; i>=0 ; i--){
            if(s.size()==0){
                nsr[i] = n;
            }else if(s.size()>0 and nums[s.top()]<=nums[i]){
                nsr[i] = s.top();
            }else if (s.size()>0 and nums[s.top()]>nums[i]){
                while(s.size()>0 and nums[s.top()]>nums[i]){
                    s.pop();
                }
                if(s.size()==0){
                    nsr[i] = n;
                }else {
                    nsr[i] = s.top();
                }
            }
            s.push(i);
        }
        
        long long ans = 0;
        
        for(int i = 0 ;  i<n ; i++){
            ans += (i-nsl[i])*(nsr[i]-i)*nums[i];
        }
        return ans;
        
        
    }
    
    long long findSubarrayMaximas(vector<int> &nums){
        int n = nums.size();
        vector<long long> ngl(n,-1);
        vector<long long> ngr(n,n);
        stack<int> s;
        for(int i = 0 ; i<n ; i++){
            if(s.size()==0){
                ngl[i] = -1;
            }else if(s.size()>0 and nums[s.top()]>nums[i]){
                ngl[i] = s.top();
            }else if (s.size()>0 and nums[s.top()]<=nums[i]){
                while(s.size()>0 and nums[s.top()]<=nums[i]){
                    s.pop();
                }
                if(s.size()==0){
                    ngl[i] = -1;
                }else {
                    ngl[i] = s.top();
                }
            }
            s.push(i);
        }
        
        while(s.size()>0){
            s.pop();
        }
        
        for(int i = n-1 ; i>=0 ; i--){
            if(s.size()==0){
                ngr[i] = n;
            }else if(s.size()>0 and nums[s.top()]>=nums[i]){
                ngr[i] = s.top();
            }else if (s.size()>0 and nums[s.top()]<nums[i]){
                while(s.size()>0 and nums[s.top()]<nums[i]){
                    s.pop();
                }
                if(s.size()==0){
                    ngr[i] = n;
                }else {
                    ngr[i] = s.top();
                }
            }
            s.push(i);
        }
        
        long long ans = 0;
        
        for(int i = 0 ;  i<n ; i++){
            ans += (i-ngl[i])*(ngr[i]-i)*nums[i];
        }
        return ans;
        
        
    }
    
    
    
    long long subArrayRanges(vector<int>& nums) {
        long long maximas = findSubarrayMaximas(nums);
        long long minimas = findSubarrayMinimas(nums);
        return maximas - minimas;
    }
};