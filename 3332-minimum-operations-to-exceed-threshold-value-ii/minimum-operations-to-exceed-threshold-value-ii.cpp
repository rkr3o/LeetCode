class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i = n-1 ; i>=0 ; i--){
            // if(nums[i]<k){
                pq.push(nums[i]);
            // }
        }
        if(pq.empty())return 0;
        
        int cnt = 0 ;
        while(!pq.empty() and pq.top()<k){
            long long x = pq.top();pq.pop();
            long long y = pq.top();pq.pop();
            long long sum = min(x,y)*2 + max(x,y);
            // if(sum<k){
            pq.push(sum);
            // }
            cnt++;
        }
        // if(!pq.empty())cnt++;
        return cnt;
    }
};