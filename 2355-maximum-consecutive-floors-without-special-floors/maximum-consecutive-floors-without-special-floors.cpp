class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
          sort(special.begin(),special.end());
          int maxima = special[0]-bottom;
          for(int i = 1 ;i <special.size() ; i++)
          {
              int val = abs(special[i]-special[i-1])-1;
              maxima=max(maxima,val);
          }
          maxima = max(top-special.back(),maxima);
          return maxima;
    }
};