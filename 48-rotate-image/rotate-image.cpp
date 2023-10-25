class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>copy=matrix;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0 ; j < m ; j++)
            {
                copy[i][j] = matrix[j][i];
            }
        }
        // printMatrix(copy);
        for (int i = 0 ; i < copy.size() ; i++)
        {
            reverse(copy[i].begin(), copy[i].end());
        }
        matrix=copy;
    }
};