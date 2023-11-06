class Solution {
public:
    int dp[366];
    int solve(int ind, vector<int>&days , vector<int>&costs)
    {
        if(ind>=days.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int option1 = costs[0]+solve(ind+1,days,costs);
        int option2 = INT_MAX;
        for(int i = ind ; i<days.size() and days[i] < days[ind]+7 ; i++)
        {
             option2= costs[1]+solve(i+1,days,costs);
        }
        int option3 = INT_MAX;
        for(int i = ind ; i<days.size() and days[i] < days[ind]+30 ; i++)
        {
             option3 = costs[2]+solve(i+1,days,costs);
        }
        return dp[ind] = min({option1,option2,option3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,days,costs);
    }
};