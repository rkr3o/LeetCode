class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> arr;
        int n = dist.size();
        for (int i = 0; i < n; i++) {
            arr.push_back(ceil((double)dist[i]/speed[i]));
        }
        sort(arr.begin(), arr.end());
        int cnt = 1;
        int time = 1;
        for (int i = 1; i < n; i++) {
            if(arr[i]-time<=0)
            {
                 return cnt;
            }
            cnt++;
            time++;
        }
        return cnt;
    }
};
