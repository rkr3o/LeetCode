class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>mp;
        int n = s.size();
        for(int i = 0; i < n ; i++)
        {
            mp[s[i]]=i;
        }
        int maxima = INT_MIN;
        for(int i = 0 ; i <n ; i++)
        {
            int ind = mp[s[i]];
            int cur = i ;
            if(ind==cur)
              continue;
            int sub = abs(ind-i-1);
            maxima = max(maxima,sub);
        }
        if(maxima==INT_MIN)return -1;
        return maxima;
    }
};