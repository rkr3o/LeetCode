class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        if(nums.empty()) return {};
        vector<int> ans;
        unordered_map<int, vector<int>> mp;
        for(int row = nums.size()-1; row >= 0; row--) {
            for(int col = 0; col < nums[row].size(); col++) 
            {    
                mp[row+col].push_back(nums[row][col]);   
            }
        }
        int diagonal = 0;
        while(mp.find(diagonal) != mp.end()) 
        {    
            for(int &num : mp[diagonal]) 
            {
                ans.push_back(num);
            }
            diagonal++;
        }
        return ans;
    }
};
