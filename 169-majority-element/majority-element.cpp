class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0 ;
        int ele ;
        int n = (int)nums.size();
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(cnt==0)
            {
                cnt++;
                ele = nums[i];
            }
            else if(nums[i]==ele)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        int x = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]==ele)
            {
               x++;
            }
        }
        if(x>n/2)return ele;
        return -1;
    }
};