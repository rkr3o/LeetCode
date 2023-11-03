// we know that if a string is an echo-substring...then it can be divided into 2 equal halves ..
// so.. let's fix the first half and try to find...out if the next half is equal to first half or not

// so start with len = 1...  use 2 pointer to compare the first half and second half...
// if both half are equal ..push that string into set ... (but this algo will be O(n^3) .. so you can optimise the set part by doing string hashing) 
// @Mr.Haller
// you will check for each len...
// i.e
// first len = 1
// then len = 2
// .
// .
// len = n/2
class Solution {
public:
    int distinctEchoSubstrings(string s) {
        
        set<string> ans;
        int n = s.size();
        for(int len = 1; len <= n / 2; len++) {
            
            int first_string_start = 0;
            int second_string_start = 0 + len;
            int equal = 0;
            while(second_string_start < n) {
                
                if(s[first_string_start] == s[second_string_start]) {
                    equal++;
                } else {
                    equal = 0;
                }

                first_string_start++;
                second_string_start++;
                if(equal == len) {
                    ans.insert(s.substr(first_string_start - len, len));
                    equal--;
                }
            }
        }

        return ans.size();
    }
};