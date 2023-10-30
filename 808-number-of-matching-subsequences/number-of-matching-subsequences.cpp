class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>charInd(26);
        for(int i = 0 ; i < s.size() ; i++)
        {
            charInd[s[i]-'a'].push_back(i);
        }
        int cnt = 0 ;
        for(int i = 0 ; i < words.size() ; i++)
        {
            int lastCharInd = -1;
            bool checkSubs = true;
            for(auto x : words[i])
            {
                auto it = upper_bound(charInd[x-'a'].begin(),charInd[x-'a'].end(),lastCharInd);
                if(it==charInd[x-'a'].end())
                {
                    checkSubs=false;
                    break;
                }
                else
                {
                    lastCharInd=*it;
                }
            }
            if(checkSubs)cnt++;
        }
        return cnt;
    }
};