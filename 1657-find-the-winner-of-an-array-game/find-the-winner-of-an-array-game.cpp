class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxima = arr[0];
        int cnt= 0 ;
        for(int i = 1 ; i < arr.size() ;i++)
        {
            if(arr[i]>maxima)
            {
                maxima = arr[i];
                cnt=0;
            }
            cnt++;
            if(cnt==k) break;
        }
        return maxima;
    }
};