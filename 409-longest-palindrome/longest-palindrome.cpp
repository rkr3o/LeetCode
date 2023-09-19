class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int>mp;
        int odd = 0;
        for(auto x : s)mp[x]++;
        int length = 0 ;
        for(auto x : mp)
        {
            if(x.second %2==0)
            {
                 length+=x.second;
            }
            else 
            {
               if(x.second >2) length+=x.second-1;
               odd++;
            }
           
        }
        return (odd > 0) ? length+1 : length;
    }
};