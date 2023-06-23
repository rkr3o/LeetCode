class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow = nums[0];  // Move one step at a time
        int fast = nums[0];  // Move two steps at a time

        // Move the slow and fast pointers until they meet
        while (true) 
        {
            slow = nums[slow];              // Move one step
            fast = nums[nums[fast]];       // Move two steps

            // Cycle detected
            if (slow == fast) {
                break;
            }
        }

        // Move the slow pointer to the beginning
        slow = nums[0];

        // Move both pointers one step at a time until they meet at the entrance of the cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;  // The duplicate number
}

};