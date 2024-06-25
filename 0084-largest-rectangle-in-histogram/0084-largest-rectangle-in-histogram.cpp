class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        vector<int> nsl(n,-1) ; 
        vector<int> nsr(n,n) ;
        stack<int> s;
        for(int i = 0 ; i<n ; i++){
            if(s.size()==0){
                nsl[i] = -1;
            }else if(s.size()>0 and heights[s.top()] < heights[i]){
                nsl[i] = s.top(); 
            }else if(s.size()>0 and heights[s.top()] >= heights[i]){
                while(s.size()>0 and heights[s.top()] >= heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    nsl[i] = -1;
                }else{
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
            }else if(s.size()>0 and heights[s.top()] < heights[i]){
                nsr[i] = s.top(); 
            }else if(s.size()>0 and heights[s.top()] >= heights[i]){
                while(s.size()>0 and heights[s.top()] >= heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    nsr[i] = n;
                }else{
                    nsr[i] = s.top();
                }
            }
            s.push(i);
        }
        
        for(int i = 0 ; i<n ; i++){
            ans = max(ans, (nsr[i]-nsl[i]-1)*heights[i]);
        }
        
        
        
        return ans;
    }
};