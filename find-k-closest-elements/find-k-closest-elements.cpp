class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        // Find the index of the element in arr that is closest to x
        while (right - left + 1 > k) {
            if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                right--;
            } else {
                left++;
            }
        }

        // Collect the k closest elements into a new vector
        vector<int> result(arr.begin() + left, arr.begin() + right + 1);
        return result;
    }
};
