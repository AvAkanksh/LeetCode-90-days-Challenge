class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
                //Sort based on starting point
        sort(intervals.begin(), intervals.end());

        // define a minheap to store ending points of each group
        priority_queue<int, vector<int>, greater<int>> pq;

        //process each interval one by one
        for(vector<int>& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if(!pq.empty() && start > pq.top()) {
                pq.pop();
            }

            pq.push(end);
        }

        return pq.size();
    }
};