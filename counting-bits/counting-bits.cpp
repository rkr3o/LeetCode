class Solution {
public:
    int getBits(int n)
    {
        int cnt = 0 ;
        while(n)
        {
            int x = n%2;
            if(x==1)cnt++;
            n>>=1;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
       vector<int>ans(n+1);
       for(int i = 0 ; i<=n ;i++)
       {
           ans[i]=(getBits(i));
       }
       return ans;
    }
};