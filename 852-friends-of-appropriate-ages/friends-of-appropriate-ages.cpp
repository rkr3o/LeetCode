class Solution {
public:
     
      int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int res = 0;
        for (int i = 0; i < ages.size(); ++i) {
            int low_bound = ages[i]/2 + 8;
            auto low_it = lower_bound(ages.begin(), ages.end(), low_bound);
            auto high_it = upper_bound(ages.begin(), ages.end(), ages[i]);
            int request = distance(low_it, high_it) - 1;
            res += max(request, 0);
        }
        return res;
    }
};