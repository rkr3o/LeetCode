class Solution {
public:
    #define ll long long 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ll gasSum = accumulate(gas.begin(),gas.end(),0*1LL);
        ll costSum = accumulate(cost.begin(),cost.end(),0*1LL);
        if(gasSum<costSum)return -1;

        int gasStation=0;
        int n = gas.size();
        
        int totalCost=0;
        for(int i = 0 ; i < n ; i++)
        {
            totalCost+=gas[i]-cost[i];
            if(totalCost<0)
            {
                totalCost=0;
                gasStation = i+1;
            }
        }
        return gasStation;
    }
};