class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>mp(26,0);
        int n = s.size();
        for(int i = 0; i < n ; i++)
        {
            mp[s[i]-'a']=i;
        }
        int maxima = INT_MIN;
        for(int i = 0 ; i <n ; i++)
        {
            int ind = mp[s[i]-'a'];
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