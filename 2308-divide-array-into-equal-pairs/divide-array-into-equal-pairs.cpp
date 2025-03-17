class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n&1){
            return false;
        }
        
        vector<int>vis(502,0);
        for(auto &x : nums){
            vis[x]++;
        }
        for(int i = 0; i<=500 ; i++){
            if(vis[i]&1){
                return false;
            }
        }
        return true;
    }
};