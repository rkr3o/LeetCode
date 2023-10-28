class Solution {
public:
    //count d and r
    //check whether the opponent is present before or curr index if yes idx--
    //remove immediate right opponent
    void solve(int ind , char ch , string &s , vector<int>&vis)
    {
        while(true)
        {
            if(s[ind]==ch and vis[ind]==false)
            {
                vis[ind]=true;
                break;
            }
            ind=(ind+1)%(int)s.size();
        }
    }
    string predictPartyVictory(string senate) {
        int d = count(senate.begin(),senate.end(),'D');
        int r = senate.size()-d;
        int i = 0 ;
        int n = senate.size();
        vector<int>vis(n,false);
        while(r>0 and d>0)
        {
            if(vis[i]==false)
            {
                if(senate[i]=='R')
                {
                    //find the opponent D
                    solve((i+1)%(int)senate.size(),'D',senate,vis);
                    d--;
                }
                else
                {
                    //find the opponent D
                    solve((i+1)%(int)senate.size(),'R',senate,vis);
                    r--;
                }
            }
            i=(i+1)%(int)senate.size();
        }
        if(r==0)return "Dire";
        return "Radiant";
    }
};