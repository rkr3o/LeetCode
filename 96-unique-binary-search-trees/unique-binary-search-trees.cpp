class Solution {
public:
    int catalan(int n)
    {
        if(n<=1)return 1 ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            ans+=catalan(i)*catalan(n-i-1);
        }
        return ans;
    }
    int numTrees(int n) {
        return catalan(n);
    }
};