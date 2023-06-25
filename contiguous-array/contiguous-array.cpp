class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
          int n = nums.size();
          if(n<=1)return 0 ;
          map<int,int>mp={{0,-1}};
          int sum = 0 , maxima = 0 ;
          for(int i = 0 ; i < nums.size() ; i++)
          {
              sum+=(nums[i]==1)?1:-1;
              if(mp.find(sum)!=mp.end())
              {
                  maxima = max(maxima , i-mp[sum]);
              }
              else
              {
                  mp[sum]=i;
              }
          }
          return maxima;
    }
};  
