class Solution {
public:
int calculateRegularCost(vector<int>& price, vector<int>& needs) {
        int cost = 0;
        for (int i = 0; i < price.size(); ++i) {
            cost += price[i] * needs[i];
        }
        return cost;
    }
int minCost(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,  map<vector<int>, int>& dp) {
        if (dp.count(needs)) {
            return dp[needs];
        }
        int regularCost = calculateRegularCost(price, needs);
        for (auto& offer : special) {
            vector<int> updatedNeeds(needs.begin(), needs.end());
            bool validOffer = true;
            for (int i = 0; i < needs.size(); ++i) {
                updatedNeeds[i] -= offer[i];
                if (updatedNeeds[i] < 0) {
                    validOffer = false;
                    break;
                }
            }
            if (validOffer) {
                regularCost = min(regularCost, offer.back() + minCost(price, special, updatedNeeds, dp));
            }
        }
        return dp[needs] = regularCost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>, int> dp;
        return minCost(price, special, needs, dp);
    }
};