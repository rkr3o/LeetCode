class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
       int xi = 0;
       for(auto x : nums)xi = xi^x;
       return xi;
    }
};