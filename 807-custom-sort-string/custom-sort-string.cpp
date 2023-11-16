class Solution {
public:
    string customSortString(string s, string t) {
       sort(t.begin(),t.end(),[&](const char &a , const char &b){
            return s.find(a)<s.find(b);
       });
       return t;
    }
};