class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices),end(prices));
        int p = prices[0]+prices[1];
        if(p<=money)
        {
            return money-p;
        }
        return money;
    }
};