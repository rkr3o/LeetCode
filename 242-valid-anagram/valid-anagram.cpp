class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char,int>mp1;
       unordered_map<char,int>mp2;
       if(s.size()>t.size() or t.size()>s.size())return false;
       for(auto x : s)mp1[x]++;
       for(auto x : t)mp2[x]++;
       for(auto x : s){
            if(mp1[x]!=mp2[x])return false;
       }
       return true;
    }
};