class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
       int xi = 0;
       for(int i = 0 ; i < nums.size() ; i++)
       {
           xi = xi^nums[i];
       } 
       return xi;
    }
};