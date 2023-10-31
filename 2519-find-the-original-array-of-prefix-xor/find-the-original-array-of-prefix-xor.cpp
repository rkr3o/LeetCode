class Solution {
public:
    vector<int> findArray(vector<int>& pre) {
        int n = pre.size();
        vector<int>ans(n);
        ans[0]=pre[0];
        for(int i = 1; i < n ; i++)
        {
             ans[i] = pre[i]^pre[i-1];
        }
        return ans;
    }
};