class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for(int i = 0 ; i < n ; i++) {
            if(a[i] <= 0) {
                a[i] = n + 1;
            }
        }

        for(int i = 0 ; i < n ; i++) {
            int pos = abs(a[i]) - 1;
            if(pos < n) {
                a[pos] = -abs(a[pos]); // Corrected sign change
            }
        }

        for(int i = 0 ; i < n ; i++) {
            if(a[i] > 0) return i + 1;
        }
        return n + 1;
    }
};
