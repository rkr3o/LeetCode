class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>st;
        for(auto x : emails){
            int atInd = x.find('@');
            string local = x.substr(0, atInd);
            string domain = x.substr(atInd);

            int plusIndex = local.find('+');
            if (plusIndex != string::npos) {
                local = local.substr(0, plusIndex);
            }
            local.erase(remove(local.begin(), local.end(), '.'), local.end());
            string ans = local + domain;
            st.insert(ans);
        }
        return st.size();
    }
};