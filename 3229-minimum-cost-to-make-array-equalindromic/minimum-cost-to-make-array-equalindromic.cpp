class Solution {
public:
    bool isPalindrome(int n) {
        string s = to_string(n);
        string t = s;  // Use the correct variable name here
        reverse(begin(t), end(t));
        return s == t;
    }

    long long minimumCost(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        int n = nums.size();
        long long s=0; long long e= n-1;
        long long midEl = nums[s+(e-s)/2];

        long long x = midEl,y=midEl;
        
        while(isPalindrome(x) == 0){
            x--;
        }
        long long int ans = 0;
        for(int i=0; i<n; i++){
            ans += abs(nums[i] - x);
        }
        while(isPalindrome(y) == 0){
            y++;
        }
        long long int ans2 = 0;
        for(int i=0; i<n; i++){
            ans2 += abs(nums[i] - y);
        }
        
        ans = min(ans,ans2);
    
        return ans;   
    }
};