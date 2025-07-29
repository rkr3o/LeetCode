class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        unordered_map<int,int>mp;
        for(auto &x:nums)
            mp[x]++;

        for(auto &[x,y]: mp){
            pq.push({y,x});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            ans.push_back({ele.second});
        }
        return ans;
    }
};