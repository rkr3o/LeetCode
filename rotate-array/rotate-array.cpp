class Solution {
public:
    void rotate(vector<int>& vec2, int k) {
        int n = vec2.size();
        if(k>n) k%=n;
        if(n-k>=0 and n-k<n)
        std::rotate(vec2.begin(), vec2.begin() + (n - k), vec2.end());
    }
};
