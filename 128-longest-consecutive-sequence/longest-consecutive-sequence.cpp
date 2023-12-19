class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==0)return 0;
        int maxima = 0 ;
        int cur = nums[0];
        int cnt=1;
        for(int i = 1 ; i < n ;i++)
        {
            if(nums[i]==cur)continue;
            if(nums[i]==cur+1)
            {
                cnt++;
                cur=nums[i];
                maxima=max(maxima,cnt);
            }
            else
            {
                cnt=1;
                cur=nums[i];
            }
        }
        maxima=max(maxima,cnt);
        return maxima;
    }
};