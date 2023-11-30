class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans=0,mul=1;
        for(int i=30;i>=0;i--){
            if(n&(1<<i)){
                ans+=mul*((1<<(i+1))-1);
                mul*=-1;
            }
        }
        return ans;
    }
};