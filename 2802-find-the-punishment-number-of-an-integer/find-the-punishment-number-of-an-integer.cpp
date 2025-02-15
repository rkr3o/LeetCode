class Solution {
public:
    bool check_possible(int ind, string &s, int target, int value) {
        if (ind == s.size()) return value == target; 
        int num = 0;
        for (int i = ind; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');  
            if (value + num > target) break;  
            if (check_possible(i + 1, s, target, value + num)) return true;
        }
        return false;
    }

    int get_sum(int num) {
        int squarred_value = num * num;
        string s = to_string(squarred_value);
        if (check_possible(0, s, num, 0)) return squarred_value;
        return 0;
    }

    int punishmentNumber(int n) {
        int ans = 0; 
        for (int i = 1; i <= n; i++) {
            ans += get_sum(i);
        }
        return ans;
    }
};
