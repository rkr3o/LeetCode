class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        int cur = 0;
        int jump = 0;
        if (nums.size() == 1)
            return 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == cur) {
                cur = farthest;
                jump++;
            }
        }
        if(cur < nums.size()-1)return -1;
        return jump;
    }
};