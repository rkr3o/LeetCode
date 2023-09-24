class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    { 
        if(strs.size()==1)return strs[0];
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs.back();
        int i = 0 ;
        int size=min(first.size(),last.size());
        string ans="";
        while(i<size)
        {
            if(first[i]==last[i])
            {
                ans+=first[i];
                i++;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};