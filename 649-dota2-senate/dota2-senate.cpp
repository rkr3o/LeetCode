class Solution {
public:
    //count d and r
    //check whether the opponent is present before or curr index if yes idx--
    // remove immediate right opponent
    bool solve(int ind , char ch , string &s)
    {
        bool left = false;
        while(true)
        {
            if(ind==0)left=true;
            if(s[ind]==ch)
            {
                s.erase(s.begin()+ind);
                break;
            }
            ind=(ind+1)%(int)s.size();
        }
        return left;
    }
    string predictPartyVictory(string senate) {
        int d = count(senate.begin(),senate.end(),'D');
        int r = senate.size()-d;
        int i = 0 ;
        while(r>0 and d>0)
        {
            if(senate[i]=='R')
            {
                //find the opponent D
                bool check = solve((i+1)%(int)senate.size(),'D',senate);
                d--;
                //if oppenet is present left side of idx 
                if(check)
                {
                    i--;
                }
            }
            else
            {
                //find the opponent D
                bool check = solve((i+1)%(int)senate.size(),'R',senate);
                r--;
                //if oppenet is present left side of idx 
                if(check)
                {
                    i--;
                }
            }
            i=(i+1)%(int)senate.size();
        }
        if(r==0)return "Dire";
        return "Radiant";
    }
};