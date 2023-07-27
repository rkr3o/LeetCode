#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int minDominoRotations(std::vector<int>& tops, std::vector<int>& bottoms) {
        int n = tops.size();
        
        // Helper function to find the minimum number of rotations needed for a given value 'x'
        auto findMinRotations = [&](int x) {
            int rotations_top = 0, rotations_bottom = 0;
            
            for (int i = 0; i < n; i++) {
                if (tops[i] != x && bottoms[i] != x) {
                    return -1; // It's not possible to make all tops or bottoms the same with value 'x'.
                }
                if (tops[i] != x) rotations_top++;
                if (bottoms[i] != x) rotations_bottom++;
            }
            
            return std::min(rotations_top, rotations_bottom);
        };
        
        int rotations = findMinRotations(tops[0]); // Check tops[0] as the candidate value.
        if (rotations != -1) return rotations;
        
        return findMinRotations(bottoms[0]); // If tops[0] didn't work, try bottoms[0].
    }
};
