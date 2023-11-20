class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> pre(travel.size()+1);
        pre[0] = 0;
        for (int i = 1; i <= travel.size(); i++) {
            pre[i] = travel[i-1] + pre[i - 1];
        }
        for(auto x : pre)cout<<x<<" ";
        cout<<endl;
        int m = -1, p = -1, g = -1;
        int cntm = 0;
        int cntg = 0;
        int cntp = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            string s = garbage[i];
            if (s.find('M') != string::npos) {
                cntm += count(s.begin(), s.end(), 'M');
                if (m == -1) m = i;
            }
            if (s.find('P') != string::npos) {
                cntp += count(s.begin(), s.end(), 'P');
                if (p == -1) p = i;
            }
            if (s.find('G') != string::npos) {
                cntg += count(s.begin(), s.end(), 'G');
                if (g == -1) g = i;
            }
        }
        //cout<<m<<p<<g<<endl;
        int sum = 0;
        if (m != -1) sum += pre[m];
        if (p != -1) sum += pre[p];
        if (g != -1) sum += pre[g];
        sum += cntm;
        sum += cntp;
        sum += cntg;
        return sum;
    }
};