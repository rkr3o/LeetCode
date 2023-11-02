class Solution {
public:
    int dp[40][40];
    int solve(int left ,int right , vector<int>&arr , map<pair<int,int>,int>&mp)
    {
        if(left==right)return 0;
        if(dp[left][right]!=-1)return dp[left][right];
        int ans = INT_MAX;
        for(int i = left ; i< right ; i++)
        {
            int leftMaxi = mp[{left,i}];
            int rightMaxi = mp[{i+1,right}];
            int leftSubtree = solve(left,i,arr,mp);
            int rightSubtree=solve(i+1,right,arr,mp);
            ans = min(ans,(leftMaxi*rightMaxi)+leftSubtree+rightSubtree);
        }
        return dp[left][right]= ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>mp;
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < n ; i++)
        {
            mp[{i,i}]=arr[i];
            for(int j = i ; j < n ; j++)
            {
                 mp[{i,j}] = max(arr[j],mp[{i,j-1}]);
            }
        }
        return solve(0,n-1,arr,mp);
    }
};