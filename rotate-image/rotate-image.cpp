class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
         int n = matrix.size();
         int m = matrix[0].size();
         vector<vector<int>>copy(n,vector<int>(m,0));
         for(int i = 0 ; i < n ; i++)
         {
             for(int j = 0 ; j < m ; j++)
             {
                 copy[j][i]=matrix[i][j];
             }
         }    
         for(int i = 0 ; i < n ; i++)
         {
             reverse(copy[i].begin(),copy[i].end());
         }
         matrix=copy;
    }
};