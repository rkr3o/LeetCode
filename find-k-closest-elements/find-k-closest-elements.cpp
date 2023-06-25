class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
         int n = arr.size();
        vector<int>ans;
        if(n==0)return ans;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0 ; i < n ;i++)
        {
            int d = abs(x-arr[i]);
            pq.push({d,arr[i]});
        }
        while(!pq.empty()and k>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};