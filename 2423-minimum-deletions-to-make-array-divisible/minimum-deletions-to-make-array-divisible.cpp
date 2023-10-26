 class Solution {
public:
    bool check(int num , unordered_map<int,int>&mp)
    {
        for(auto x: mp)
        {
            if(x.first%num!=0)return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp2;
        for(auto x: nums) mp[x]++;
        for(auto x : numsDivide)mp2[x]++;
        set<int>st(nums.begin(),nums.end());
        for(auto x : st)
        {
            bool res = check(x,mp2);
            if(res)
            {
                int totalDelete = 0 ;
                for(auto y : mp)
                {
                    if(y.first<x)
                        totalDelete+=y.second;
                }
                return totalDelete;
            }
        }  
        return -1;
    }
};