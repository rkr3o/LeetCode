class Solution {
public:
    #define ll long long
    ll countSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), maxi=INT_MIN;
        ll ans=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }

        int curr=0, start=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi) curr++;

            while(curr>=k){
                ans+=(n-i);
                if(nums[start]==maxi) curr--;
                start++;
            } 
        }
        return ans;
    }
};