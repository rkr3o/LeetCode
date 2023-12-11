class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int>ans;
      int n = s.size();
      vector<int>ind(26,0);
      for(int i = 0 ; i < n ; i++)
      {
          ind[s[i]-'a']=i;
      } 
      int maxima = 0 ;
      //cout<<ind[0]<<endl;
      int prev = 0 ;
      int sum = 0 ;
      for(int i = 0 ; i < n ; i++)
      {
          //find maximum index of element
          maxima = max(maxima,ind[s[i]-'a']);
          if(i==maxima)
          {
              if(ans.empty())
              {
                  ans.push_back(i+1);
                  prev=i;
              }
              else 
              {
                  ans.push_back(i-prev);
                  prev=i;
              }
              maxima=0;
          }
      }
       return ans;
    }
};