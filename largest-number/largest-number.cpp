class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        if(nums[0]==0)return "0";
        for (auto x : nums) {
            ans += to_string(x);
        }
        return ans;
    }
};
