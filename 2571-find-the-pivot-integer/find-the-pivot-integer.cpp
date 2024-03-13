class Solution {
public:
    int pivotInteger(int n) {
        vector<int>pre(n);
        pre[0]=1;
        for(int i = 1; i < n ; i++)
        {
            pre[i]+=(i+1)+pre[i-1];
        }
        int sum = 0 ;
        for(int i = n ; i>=1 ;i--)
        {
            sum+=i;
            if(pre[i-1]==sum)return i;
        }
        return -1;
    }
};