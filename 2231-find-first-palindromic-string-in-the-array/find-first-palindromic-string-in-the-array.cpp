class Solution {
public:
    bool check(string &s){
        string t = s ;
        reverse(begin(t),end(t));
        return s==t;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto x : words){
            if(check(x))return x;
        }  
        return "";     
    }
};