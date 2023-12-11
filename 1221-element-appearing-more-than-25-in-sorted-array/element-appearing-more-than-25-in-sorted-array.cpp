class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0 ; i < n ; i++)
        {
             int cnt = 0 ;
             for(int j = i ; j < n; j++)
             {
                 if(arr[i]==arr[j])
                 {
                     cnt++;
                 }
                 if(cnt>n/4)return arr[i];
             }
        }
       return -1;
    }
};