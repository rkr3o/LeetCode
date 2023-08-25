class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int evenMoves = 0, oddMoves = 0;

        for (int i = 0; i < n; i++) {
            int leftNeighbor = i > 0 ? nums[i - 1] : INT_MAX;
            int rightNeighbor = i < n - 1 ? nums[i + 1] : INT_MAX;

            int minNeighbor = min(leftNeighbor, rightNeighbor);

            if (i % 2 == 0) {
                evenMoves += max(0, nums[i] - (minNeighbor - 1));
            } else {
                oddMoves += max(0, nums[i] - (minNeighbor - 1));
            }
        }

        return min(evenMoves, oddMoves);
    }
};
