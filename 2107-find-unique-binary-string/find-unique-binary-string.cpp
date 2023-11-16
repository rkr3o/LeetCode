class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        for(auto x:nums)st.insert(x);
        string s=nums[0];
        for(int i =  0 ; i < s.size() ; i++)
        {
            char original = s[i];
            for(char ch ='0' ; ch<='1' ; ch++)
            {
                  s[i]=ch;
                  if(st.find(s)==st.end())
                  {
                      return s;
                  }
            }
            s[i]=original;
        }
        return "";
    }
};