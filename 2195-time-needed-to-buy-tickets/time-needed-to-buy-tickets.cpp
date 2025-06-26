class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int tt = 0 ;
        for(int i = 0 ; i < tickets.size(); i++){
            if(i <= k){
                tt += min(tickets[k], tickets[i]);
            } else {
                tt += min(tickets[k] - 1, tickets[i]);
            }
        }
        return tt;
    }
};
