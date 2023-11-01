class Solution {
public:
bool solve(vector<int>& nums,vector<bool>& v,int currSum,int index,int target,int k)
    {
        //base case
        if(k==0)
            return true;
        if(currSum>target)
            return false;
        if(currSum==target)
            return solve(nums,v,0,0,target,k-1);

        for(int i=index;i<nums.size();i++)
        {
            if(v[i]) continue;
            v[i]=true;
            if(solve(nums,v,currSum+nums[i],i+1,target,k))
                return true;
            v[i]=false;
            if(currSum==0) break;
        }
            return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for(int i=0;i<nums.size();i++)
            total+=nums[i];
        if(total%k!=0 || k>nums.size())
            return false;
        int target=total/k; //target sum 
        vector<bool> v(nums.size(),false);
        sort(nums.begin(),nums.end());
        if(nums[0]>target)
            return false;
        return solve(nums,v,0,0,target,k);
    }
    
};