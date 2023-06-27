class Solution {
public:
vector<int>v;
    Solution(vector<int>& w) 
    {
        for(auto x : w)
        {
            if(v.empty())v.push_back(w[0]);
            else
            {
                v.push_back(v.back()+x);
            }
        }    
    }
    
    int pickIndex() {

        int randweight = rand()%(v.back());
        auto x = upper_bound(v.begin(),v.end(),randweight)-v.begin();
        return x;
        
    }
};
