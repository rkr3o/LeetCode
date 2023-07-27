class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        auto compare = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(compare)> pq(compare);
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};

        while (!pq.empty()) 
        {
            auto p = pq.top();
            pq.pop();
            int element = p.first;
            int row = p.second.first;
            int col = p.second.second;

            res = max(res, element);

            if (row == n - 1 && col == n - 1)
                return res;
            for(int i = 0 ; i < 4 ; i++)
            {
                int nrow = row+drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 and ncol >=0 and nrow< n and ncol < n and !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    pq.push({grid[nrow][ncol] , {nrow,ncol}});
                }
            }
             
        }
        return -1;
    }
};
//time complexity: O(n^2*logn)
// pq contains at most n^2 elements, pop time complexity each time is is O(logn^2) = O(2*logn)
// At most we will pop n^2 times
