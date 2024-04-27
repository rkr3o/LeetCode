class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        vector<vector<int>>bucket(nums.size()+1);
        for(auto x : nums)
            mp[x]++;
        for(auto &[x,y] : mp){
            bucket[y].push_back(x);
        }
        //use bucket sort
        for(int i = bucket.size()-1; i >=0 ; --i){
            vector<int>curr_bucket_elem=bucket[i];
            if(curr_bucket_elem.size() > 0)
            {
                int j = 0;
                while(ans.size()<k and j<curr_bucket_elem.size())
                {
                    ans.push_back(curr_bucket_elem[j++]);
                }
            }
        }
        return ans;
    }
};