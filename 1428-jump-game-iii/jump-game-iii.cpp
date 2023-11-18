class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        q.push(start);
        vector<int>vis(n,0);
        while(!q.empty())
        {
            int ind = q.front();
            q.pop();
            vis[ind]=1;
            if(arr[ind]==0)return true;
            int back = ind-arr[ind];
            int front = ind+arr[ind];
            if(front < n and !vis[front])
            {
                q.push(front);
            }
            if(back>=0 and !vis[back])
            {
                q.push(back);
            }
        }
        return false;
    }
};