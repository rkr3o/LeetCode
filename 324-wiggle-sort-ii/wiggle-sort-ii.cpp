class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>copy=nums;
        sort(begin(copy),end(copy));
        int n = nums.size();
        int j = n-1;
        for(int i = 1 ; i < n ; i+=2)
        {
            nums[i]=copy[j--];
        }
        for(int i = 0 ; i < n ; i+=2)
        {
            nums[i]=copy[j--];
        }
        
    }
};