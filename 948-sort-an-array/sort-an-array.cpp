class Solution {
public:
    void merge(int l, int mid, int r , vector<int>& arr) {
         vector<int> temp;
         int left = l;
         int right = mid + 1;
         
         while (left <= mid && right <= r) {
             if (arr[left] <= arr[right]) {
                 temp.push_back(arr[left]);
                 left++;
             } else {
                 temp.push_back(arr[right]);
                 right++;
             }
         }
         
         while (left <= mid) {
             temp.push_back(arr[left]);
             left++;
         }
         
         while (right <= r) {
             temp.push_back(arr[right]);
             right++;
         }
         
         for (int i = l; i <= r; i++) {
             arr[i] = temp[i - l];
         }
    }

    void mergeSort(int low, int high, vector<int>& nums) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(low, mid, nums);
        mergeSort(mid + 1, high, nums);
        merge(low, mid, high, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n - 1, nums);
        vector<int> ans = nums;
        return ans;
    }
};
