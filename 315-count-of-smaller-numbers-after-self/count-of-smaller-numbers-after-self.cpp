class Solution {
public:
    void merge(int low, int mid, int high, vector<pair<int,int>>& v, vector<int>& count) {
        vector<pair<int, int>> temp;
        int left = low;
        int right = mid + 1;
        int rightCount = 0; // Count of smaller elements on the right side

        while (left <= mid) 
        {
            while (right <= high && v[right].second < v[left].second) {
                rightCount++; // Count smaller elements on the right
                temp.push_back(v[right++]);
            }
            count[v[left].first] += rightCount;
            temp.push_back(v[left++]);
        }

        while (right <= high) {
            temp.push_back(v[right++]);
        }

        for (int i = low; i <= high; i++) {
            v[i] = temp[i - low];
        }
    }

    void mergeSort(int low, int high, vector<pair<int,int>>& nums, vector<int>& ans) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        mergeSort(low, mid, nums, ans);
        mergeSort(mid + 1, high, nums, ans);
        merge(low, mid, high, nums, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({ i, nums[i] });
        }
        vector<int> ans(n, 0);
        mergeSort(0, n - 1, v, ans);
        return ans;
    }
};
