class Solution {
public:
    int jump(vector<int>& nums) {
        int maxima = 0 ;
        int jumps = 0 ;
        int cur= 0 ;
        for(int i = 0 ; i < nums.size()-1 ; i++)
        {
            maxima = max(maxima,nums[i]+i);
            if(i==cur)
            {
                cur=maxima;
                jumps++;
            }
        }
        if(cur<nums.size()-1)return -1;
        return jumps;
    }
};