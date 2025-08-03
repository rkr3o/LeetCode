class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int sum = 0, maxima = 0;
        int left = 0, right = 0;

        auto checkReach = [&](int left, int right) {
            int op1 = abs(left - startPos) + abs(right - left);
            int op2 = abs(right - startPos) + abs(right - left);
            return min(op1, op2) <= k;
        };

        while(right < n ){
            sum += fruits[right][1];
            while (left <= right && !checkReach(fruits[left][0], fruits[right][0])) {
                sum -= fruits[left][1];
                left++;
            }
            maxima = max(sum, maxima);
            right++;
        }
        return maxima;
    }
};
