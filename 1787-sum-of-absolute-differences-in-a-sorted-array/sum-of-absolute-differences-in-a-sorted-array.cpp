class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,0);
        pre[0]=nums[0];
        for(int i = 1 ; i < n ; i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        vector<int>ans(n,0);
        for(int i = 0 ; i < n ; i++)
        {
             int leftSum   = pre[i] - nums[i];
            int rightSum  = pre[n-1] - pre[i];
            
            int leftCount  = i;
            int rightCount = n-i-1;
            
            int leftTotal  = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i]*rightCount);
            
            ans[i] = leftTotal + rightTotal;
        }
        return ans;
    }
};