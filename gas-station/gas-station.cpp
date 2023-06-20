class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
          long long sum =  accumulate(gas.begin(),gas.end(),0*1LL);
          long long sum2 = accumulate(cost.begin(),cost.end(),0*1LL);
          if(sum<sum2)return -1;

          long long cur = 0 ;
          int start = 0 ;
          for(int i = 0 ; i < (int)gas.size() ; i++)
          {
              cur+=(gas[i]-cost[i]);
              if(cur<0)
              {
                  cur = 0 ;
                  start=i+1;
              }
          }
          return start;
    }
};