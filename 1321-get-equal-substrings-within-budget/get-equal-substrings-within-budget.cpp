class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
         int sum = 0 ;
         int maxima = 0;
         int n = s.size();
         for(int right = 0 , left = 0 ; right < n ; right++)
         {
             sum+=abs((s[right]-'a')-(t[right]-'a'));
             while(sum>maxCost)
             {
                 sum-=abs((s[left]-'a')-(t[left]-'a'));
                 left++;
             }
             maxima = max(maxima,right-left+1);
         }
         return maxima;
    }
};