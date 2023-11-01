class Solution {
public:
    map<pair<int, vector<int>>, int> mp;
    int solve(int ind, vector<int>& price, vector<int> needs, vector<vector<int>>& special) {
        if (ind == special.size()) {
            int res = 0;
            for (int i = 0; i < needs.size(); i++) {
                res += needs[i] * price[i];
            }
            return res;
        }
        if (mp.find({ind, needs}) != mp.end()) return mp[{ind, needs}];
        // Reject offer
        int reject = solve(ind + 1, price, needs, special);
        // Apply offer
        vector<int> originalNeeds = needs;
        bool canUseOffer = true;
        for (int i = 0; i < needs.size(); i++) {
            needs[i] = needs[i] - special[ind][i]; // Decrement the need;
            if (needs[i] < 0) {
                return mp[{ind, originalNeeds}] = reject; // Can't use this offer
            }
        }
        int accept = special[ind][needs.size()] + solve(ind, price, needs, special);
        return mp[{ind, originalNeeds}] = min(accept, reject);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(0, price, needs, special);
    }
};
