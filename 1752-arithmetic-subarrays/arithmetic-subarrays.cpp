class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& v, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++) {
            if(abs(l[i] - r[i]) > 1) {
                int start = l[i];
                int last = r[i]+1;
                vector<int> temp(v.begin() + start, v.begin() + last);
                sort(begin(temp), end(temp));
                int diff = temp[1] - temp[0];
                int f = 0;
                // for(auto x : temp)cout<<x<<" ";
                // cout<<endl;
                for(int j = 1; j < temp.size(); j++) {
                    if(temp[j] - temp[j-1] != diff) {  // Fix: Change temp[i] to temp[j]
                        f = 1;
                        break;
                    }
                }
                if(f == 0) {
                    ans.push_back(true);
                } else {
                    ans.push_back(false);
                }
            }
            else
            {
                ans.push_back(true);
            }
        }
        return ans;
    }
};
