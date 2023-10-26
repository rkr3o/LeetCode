class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int numGcd = numsDivide[0];
        int n = nums.size();
        for(auto x: numsDivide)
        {
             numGcd = __gcd(numGcd,x);
        }
        int cnt = 0 ;
        for(auto x : nums)
        {
            if(numGcd % x)cnt++;
            else break;
        }
        return (cnt==n)?-1:cnt;
    }
};