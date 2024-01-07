class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long,int>mp[n];
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                 long diff = (long)nums[i]-nums[j];
                 auto it = mp[j].find(diff);
                 int cntj =0;
                 if(it==mp[j].end())
                 {
                     cntj=0;
                 }
                 else{
                     cntj=it->second;
                 }
                 mp[i][diff]+=cntj+1;
                 cnt+=cntj;
            }
        }
        return cnt;
    }
};