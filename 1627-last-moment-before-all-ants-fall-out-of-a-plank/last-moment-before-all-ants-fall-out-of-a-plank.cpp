class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
         int maxima = 0 ;
         for(int i = 0 ; i < left.size() ; i++)
         {
             maxima = max(maxima, left[i]);
         }
         for(int i = 0 ; i < right.size() ; i++)
         {
             maxima = max(maxima,n-right[i]);
         }
         return maxima;
    }
};