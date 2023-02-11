class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {    
        vector<int> ans(n,-1);
        // ans[0] = 0;
        // {{currentPosition,distance},color} 
        // red = 0;
        // blue = 1;
        vector<vector<int>> redAdjList(n);
        for(auto x: redEdges){
            redAdjList[x[0]].push_back(x[1]);
        }
        vector<vector<int>> blueAdjList(n);
        for(auto x: blueEdges){
            blueAdjList[x[0]].push_back(x[1]);
        }
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},-1});
        unordered_set<string>visitedRed,visitedBlue;
        visitedRed.insert("0_-1");
        visitedBlue.insert("0_-1");
        while(!q.empty()){
            pair<pair<int,int>,int> curr = q.front();
            q.pop();
            cout<<curr.first.first<<" "<<curr.first.second<<" "<<curr.second<<endl;
            if(ans[curr.first.first]==-1){ans[curr.first.first]=curr.first.second;}
            cout<<"ans["<<curr.first.first<<"] : "<<ans[curr.first.first]<<endl;
            // else{ans[curr.first.first]= min(curr.first.second,ans[curr.first.first]);}
            if(curr.second!=1){
                for(auto x : blueAdjList[curr.first.first] ){
                cout<<"blue"<<endl;

                    string strCheck = to_string(x)+"_"+to_string(curr.second);
                    if(!visitedBlue.count(strCheck)){
                        visitedBlue.insert(strCheck);
                        q.push({{x,curr.first.second+1},1});
                    }
                }
            }
            if(curr.second!=0){
                for(auto x : redAdjList[curr.first.first] ){
                    cout<<"red"<<endl;
                    cout<<x<<endl;
                    string strCheck = to_string(x)+"_"+to_string(curr.second);
                    if(!visitedRed.count(strCheck)){
                        visitedRed.insert(strCheck);
                        q.push({{x,curr.first.second+1},0});
                    }
                }
            }
        }
        return ans;
        
    }
};