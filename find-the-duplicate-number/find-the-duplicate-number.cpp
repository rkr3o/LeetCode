class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        //check for cycle
        while(true)
        {
            slow = nums[slow];//single stps
            fast = nums[nums[fast]];//two steps

            if(slow==fast)break;
        }
        slow = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast =  nums[fast];
        }

        return slow;
    }
};