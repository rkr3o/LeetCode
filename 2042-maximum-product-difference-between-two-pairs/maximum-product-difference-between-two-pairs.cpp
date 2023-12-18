class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxima = INT_MIN;
        int secmaxima = INT_MIN;
        int minima = INT_MAX; 
        int secminima = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxima) {
                secmaxima = maxima;
                maxima = nums[i];
            } else if (nums[i] > secmaxima) {
                secmaxima = nums[i];
            }

            if (nums[i] < minima) {
                secminima = minima;
                minima = nums[i];
            } else if (nums[i] < secminima) {
                secminima = nums[i];
            }
        }

        // cout << maxima << " " << secmaxima << endl;
        // cout << minima << " " << secminima << endl;

        return abs((minima * secminima) - (maxima * secmaxima));
    }
};
