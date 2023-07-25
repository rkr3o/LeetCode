class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0, unbalanced = 0;
        for(auto x : s) {
            if(x == '[') open++;
            else {
                if(open > close) // i.e we have an extra open [ to be used in a pair
                    close++;
                else unbalanced++;
            }
        }
        return (unbalanced+1)/2;
    }
};