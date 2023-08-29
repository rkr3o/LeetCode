class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<=2)return -1;
        int ele;
        int l = 0 ; 
        int h = n-1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(arr[mid]<arr[mid+1])
            {
                l = mid+1;
            }
            else
            {
                 h = mid-1;
            }
        }
      return l;
    }
};