class Solution {
    #define pii pair<int,int>
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();  // Get the number of friends
        vector<pii> events;  // To store both arrival and departure events

        // Record the arrival and departure times as events
        for(int i = 0; i < n; ++i){
            events.push_back({times[i][0], i});   // Arrival event for friend i
            events.push_back({times[i][1], -1});  // Departure event for friend i (~i is used to differentiate departure)
        }

        // Sort events by time
        sort(events.begin(), events.end());

        // Min-heap to track empty chairs (smallest available chair)
        priority_queue<int, vector<int>, greater<int>> emptyChairs;

        // Min-heap to track occupied chairs and their release times (departure)
        priority_queue<pii, vector<pii>, greater<pii>> occupiedChairs;

        // Initially, all chairs are empty (0 to n-1)
        for(int i = 0; i < n; ++i)
            emptyChairs.push(i);
        
        // Process each event in chronological order
        for(auto& event : events){
            int time = event.first;       // Event time (arrival or departure)
            int friendNo = event.second;  // Friend index (positive for arrival, negative for departure)

            // Free up chairs for any friends who have departed by this time
            while(!occupiedChairs.empty() && occupiedChairs.top().first <= time){
                emptyChairs.push(occupiedChairs.top().second);  // Return chair to available pool
                occupiedChairs.pop();  // Remove the departure event
            }

            if(friendNo >= 0){  // If it's an arrival event
                int chair = emptyChairs.top();  // Get the smallest available chair
                emptyChairs.pop();  // Remove it from the pool of empty chairs

                // Check if the current friend is the target friend
                if(friendNo == targetFriend)
                    return chair;  // Return the chair number assigned to the target friend
                
                // Assign the chair to the current friend and record their departure time
                occupiedChairs.push({times[friendNo][1], chair});
            }
        }
        return -1;  // Shouldn't reach here as targetFriend will always be processed
    }
};