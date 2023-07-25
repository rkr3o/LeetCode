class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt = 0 ;
        int l = 0 , h = 0 ;
        while (l < g.size() and h < s.size())
        {
            if (s[h] >= g[l])
            {
                cnt++;
                h++;
                l++;
            }
            else
            {
                h++;
            }
        }

        return cnt;
    }
};