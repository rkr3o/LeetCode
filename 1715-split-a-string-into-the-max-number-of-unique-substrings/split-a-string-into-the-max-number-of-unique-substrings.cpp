class Solution {
public:
    void solve(int ind , string s , unordered_set<string>&st , int &ans)
    {
        ans=max(ans,(int)st.size());
        if(ind>=s.size())return;
        string temp="";
        for(int i = ind ; i < s.size() ; i++)
        {
            temp+=s[i];
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                solve(i+1,s,st,ans);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) 
    {
        int ans = 0;
        unordered_set<string>st;
        solve(0,s,st,ans);
        return ans;
    }
};