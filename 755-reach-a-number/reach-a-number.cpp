class Solution {
public:
    int reachNumber(int target) {
        int moves = 0;
        int total = 0;
        target = abs(target);
        
        while (total < target || (total - target) % 2 != 0) {
            moves++;
            total += moves;
        }
        
        return moves;
    }
};
