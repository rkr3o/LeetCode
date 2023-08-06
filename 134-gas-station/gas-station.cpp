class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int TotalGas = accumulate(gas.begin(),gas.end(),0);
        int TotalCost = accumulate(cost.begin(),cost.end(),0);
        if(TotalGas < TotalCost)return -1;

        int start = 0 ;
        int cur = 0 ;
        int n = cost.size();
        for(int i = 0 ; i < n ; i++)
        {
            cur+= gas[i]-cost[i];
            if(cur<0)
            {
                start = i+1;
                cur = 0;
            }
        }
        return start;
    }
};

  