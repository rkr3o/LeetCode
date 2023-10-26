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
/*
Little bit of maths here we have to think how can we check whole numsDivide array is divisible by a number without traversing whole numsDivide array and checking one by one each element is divisibel by nums[i] or not . Becuase this will give tle --> O(n^2)
So we know a property is there by which a set of elemnts can be checked if they are divisible by some number or not and that is GCD.
Since gcd is common divisor of all the numbers in set if gcd is divible by a number it means all the numbers will be divisible by that number . So we can find the gcd of whole numsDivide array and check divisiblity by nums array in sorted way one by one .
*/