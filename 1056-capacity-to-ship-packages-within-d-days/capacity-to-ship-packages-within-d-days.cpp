class Solution {
public:
    bool check(int wt, vector<int>& weights, int days) {
        int shipDays = 1;  
        int totalWt = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (totalWt + weights[i] <= wt) {
                totalWt += weights[i];
            } else {
                shipDays++;
                totalWt = weights[i];  
            }
        }
        return shipDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); 
        int high = accumulate(weights.begin(), weights.end(), 0);  
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
