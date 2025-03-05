class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0 ;
        long long base_row = n+(n-1);
        long long above = base_row-2;
        cout<<above<<endl;
        if(n==1)return 1;
        for(int i = 1 ; i < n-1 ;i++){
            above+=(n-2);
        }
        // cout<<(above*2)+base_row<<endl;
        ans = (above*2)+base_row;
        return ans;
    }
};