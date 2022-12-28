class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans = 0;
        priority_queue<int> heap(piles.begin(),piles.end());
        for(int i = 0 ; i<k ; i++){
            int top = heap.top();
            top-=top/2;
            heap.pop();
            heap.push(top);
        }
        while(!heap.empty()){
            ans+=heap.top();
            heap.pop();
        }
        return ans;
    }
};