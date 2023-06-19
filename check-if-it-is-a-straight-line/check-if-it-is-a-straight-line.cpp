class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        // Calculate the slope between the first two points
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];
        int slopeX = x1 - x0;
        int slopeY = y1 - y0;
        
        // Check the slope between each pair of points
        for (int i = 2; i < n; i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            
            // Calculate the slope between the current point and the first point
            int currSlopeX = x - x0;
            int currSlopeY = y - y0;
            
            // If the slopes are not equal, the points do not lie on a straight line
            if (slopeX * currSlopeY != slopeY * currSlopeX)
                return false;
        }
        
        return true;
    }
};
