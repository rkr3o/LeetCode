class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxima = 1;
        if(nums.size()==1)return 1;
        if (nums.empty()) return 0;

        int n = nums.size();
        int prev = nums[0];
        int cnt = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1 ; i < n ; i++){
            if(nums[i]==nums[i-1])continue;
            if(nums[i]-nums[i-1]==1){
                cnt++;
                maxima = max(maxima, cnt);
            }
            else{
                cnt=1;
            }
        }
        return maxima;
    }
};
// 1 2 3 4 100 200 