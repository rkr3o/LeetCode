class Solution {
public:
    int get_sum(string s){
        int sum = 0 ;
        for(auto x : s){
            sum+=(x-'0');
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(auto x : nums){
            int sum = get_sum(to_string(x));
            // cout<<sum<<" "<<x<<endl;
            mp[sum].push_back(x);
        }
        int is_value_present = false;
        int maxima = 0;
        for(auto &[x,y]:mp){
            if(y.size()>1){
                is_value_present = true;
                sort(y.rbegin(), y.rend());
                maxima = max(maxima, (y[0]+y[1]));
            }
        }   

        if(is_value_present) return maxima;
        return -1;
    }
};