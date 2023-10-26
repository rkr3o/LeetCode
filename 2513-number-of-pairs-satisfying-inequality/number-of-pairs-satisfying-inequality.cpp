class Solution {
public:
    long long cnt;
    void merge(int low, int mid, int high, vector<int>& v ,int diff) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;  
        while (left <= mid && right <= high) {
            if (v[left] <= v[right]+diff) 
            {
                cnt+=(high-right+1);
                left++;
            } else {
                right++;
            }
        }
        left=low;
        right=mid+1;
        while (left <= mid && right <= high) {
            if (v[left] <= v[right]) 
            {
                temp.push_back(v[left]);
                left++;
            } else {
                temp.push_back(v[right]);
                right++;
            }
        }
        while (left <= mid) 
        {
            temp.push_back(v[left]);
            left++;
        }
        while (right <= high) 
        {
            temp.push_back(v[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            v[i] = temp[i - low];
        }    
    }
    void  mergeSort(int left, int high, vector<int>& nums,int diff) {
        if (left >= high) return ;
        int mid = (left + high) / 2;
        mergeSort(left, mid, nums,diff);
        mergeSort(mid + 1, high, nums,diff);
        merge(left, mid, high, nums,diff);   
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        if(nums1.size()!=nums2.size())return 0;
        vector<int> c(n);
        cnt=0;
        for (int i = 0; i < n; i++) {
            c[i] = nums1[i] - nums2[i];
        }
        mergeSort(0, n - 1, c , diff);
        return cnt;
    }
};