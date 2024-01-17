class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
    int n = v.size();
   map<int, int>mp;
   for (int i = 0 ; i < n ; i++)
   {
      mp[v[i]]++;
   }
 map<int,int>up;
   for (auto it : mp)
   {
      up[it.second]++;
   }

   for (auto x : up)
   {
       if(x.second>1)
         return false ;
   }
   
   return true;

    }
};