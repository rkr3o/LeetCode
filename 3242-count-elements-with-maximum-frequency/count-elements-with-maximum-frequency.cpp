class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxima = 1;
        unordered_map<int,int>mp;
        for(auto x : nums){
            mp[x]++;
            maxima = max(maxima,mp[x]);
        }
        int cnt = 0 ;
        for(auto x : mp){
            if(x.second==maxima)
                cnt+=x.second;
        }
        return cnt;
    }
};