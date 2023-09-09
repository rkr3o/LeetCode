class Solution {
public:
    string addStrings(string s, string t) {
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        
        string temp;
        
        int n = max(s.size(), t.size());
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int a = i < s.size() ? s[i] - '0' : 0; // Ensure we don't access out of bounds
            int b = i < t.size() ? t[i] - '0' : 0; // Ensure we don't access out of bounds
            int sum = a + b + carry;
            carry = sum / 10;
            temp += to_string(sum % 10);
        }
        
        if (carry > 0) {
            temp += to_string(carry);
        }
       
        reverse(temp.begin(), temp.end()); // Reverse the result back
        
        return temp;
    }
};
