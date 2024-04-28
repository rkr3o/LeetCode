class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int minima = prices[0] ;
        for(int i = 0 ; i < n; i++)
        {
            profit = max(prices[i]-minima,profit);            
            minima = min(minima,prices[i]);
        }
        return profit;
    }
};