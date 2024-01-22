class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        int miss = -1;
        int n = nums.size();
        int dup=-1;
        for(auto x : nums)
        {
            mp[x]++;
            if(mp[x]>1)
                dup = x;
        }
        int cnt = 1 ;
        for(auto x : mp)
        {
            if(x.first==cnt)cnt++;
            else {
                miss = cnt;
            }
        }
        if(miss==-1)miss=n;
        return {dup,miss};
    }
};