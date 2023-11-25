class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(); 
        int pre = 0 ;
        int suff = accumulate(begin(nums),end(nums),0);
        vector<int>ans(n,0);
        for(int i = 0 ; i < n ; i++)
        {
            pre+=nums[i];
            int leftSum   = pre  - nums[i];
            int rightSum  = suff - pre;
            int leftCount  = i;
            int rightCount = n-i-1;
            int leftTotal  = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i]*rightCount);
            
            ans[i] = leftTotal + rightTotal;
        }
        return ans;
    }
};