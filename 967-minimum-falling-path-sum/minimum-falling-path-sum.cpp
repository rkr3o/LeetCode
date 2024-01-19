class Solution {
    int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, 
vector<vector<int> > &dp){
    
    // Base Conditions
    if(j<0 || j>=m)
        return 1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + getMaxUtil(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= min(up,min(leftDiagonal,rightDiagonal));
    
}
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
    int m = matrix[0].size();
    
    //vector<vector<int>> dp(n,vector<int>(m,0));
    vector<int>front(n,0);
    for(int j=0; j<m;j++){
        front[j]=matrix[0][j];
    }

    for(int i = 1 ; i < n ;i++)
    {
        vector<int>temp(n,0);
      for(int j = 0 ; j < m ; j++)
        {
              int up = matrix[i][j] + front[j];
              
              int ld = matrix[i][j];
              if(j-1>=0)
              {
                  ld+=front[j-1];
              }else
              ld+=1e9;

              int rd=matrix[i][j];
              if(j+1<m)
              {
                  rd+=front[j+1];
              }else rd+=1e9;
              
    
             temp[j]= min(up,min(ld,rd));
        }

        front=temp;
    }
    
    int maxi = INT_MAX;

    for(int i = 0 ; i < m; i++)
    {
        maxi=min(maxi,front[i]);
    }

    return maxi;
    }
};