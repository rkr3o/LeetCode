class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
       int j = 0 ;
       vector<string>ans;
       for(int i = 1 ; i <= n ; i++)
       {
            if(i==target[j])
            {
                j++;
                ans.push_back("Push");
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(j==target.size())
            {
                return ans;
            }
       }
       return ans;
    }
};