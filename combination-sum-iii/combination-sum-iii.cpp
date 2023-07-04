class Solution {
public:
    void solve(int idx , int range , int t ,vector<int>&ds , vector<vector<int>>&ans)
    {
         if(range==0)
         {
             if(t==0)
             {
                 ans.push_back(ds);
             }
             return;
         }
         for(int i = idx;  i<=9 ; i++)
         {
             if(i>t)break;
             ds.push_back(i);
             solve(i+1,range-1,t-i,ds,ans);
             ds.pop_back();
         }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(1,k,n,ds,ans);
        return ans;
    }
};