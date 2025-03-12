class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int maxima = 0 ;
        int minima = 0;
        for(auto &x : nums){
            if(x<0){
                maxima++;
            }
            else if(x>0){
                minima++;
            }
        }
        return max(maxima,minima);
    }
};