class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops=0;
        int maxFuel = startFuel;

        priority_queue<int>pq;
        int i = 0 ; 
        int n = stations.size();
        while(maxFuel<target)
        {
            while(i<n and stations[i][0] <= maxFuel)
            {
                pq.push(stations[i++][1]);
            }
            if(pq.empty())return -1;
            maxFuel+=pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};