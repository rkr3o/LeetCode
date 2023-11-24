class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(),piles.end());
        int size = piles.size()/3;
        int val = 0 ;
        for(int i = size ; i < piles.size() ; i+=2)
           val+=piles[i];
        return val;
    }
};