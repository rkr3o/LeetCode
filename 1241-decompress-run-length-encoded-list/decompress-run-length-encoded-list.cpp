class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0 ; i <= n-2 ; i+=2)
        {
            int freq = nums[i];
            int val = nums[i+1];
            while(freq--)ans.push_back(val);
        }
        return ans;
    }
};