class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)return 0;
        int maxima = 0 ;
        //preety simple if i-1th day is small means we can but it and sell it to ith day and we need total sum
        for(int i =1 ; i < n ; i++)
        {
            maxima += max(0,prices[i]-prices[i-1]);
        }
        return maxima;
    }
};