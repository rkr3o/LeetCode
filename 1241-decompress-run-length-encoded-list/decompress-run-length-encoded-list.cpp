class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0 ; i <= n-2 ; i+=2)
        {
            ans.insert(ans.end(),nums[i],nums[i+1]);
        }
        return ans;
    }
}; 