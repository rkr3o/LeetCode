class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> valid;
        vector<vector<string>>ans;
        for(auto &x : strs){
            string sort_str = x;
            sort(sort_str.begin(),sort_str.end());
            valid[sort_str].push_back(x);
        }
        for(auto &[x,y] : valid){
            ans.push_back(y);
        }
        return ans;
    }
};