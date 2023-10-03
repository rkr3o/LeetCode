class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        
        for (auto x : a)
            mp1[x]++;
        for (auto x : b)
            mp2[x]++;
        
        int maxima1 = 0, maxima2 = 0;
        int freqmaxima1 = 0;
        int freqmaxima2 = 0;
        
        for (auto& [x, y] : mp1) {
            if (y > freqmaxima1) {
                maxima1 = x;
                freqmaxima1 = y;
            }
        }
        
        for (auto& [x, y] : mp2) {
            if (y > freqmaxima2) {
                maxima2 = x;
                freqmaxima2 = y;
            }
        }
        
        int cnt1 = 0;
        int cnt2 = 0;
        bool f = 0;
        bool f2 = 0;
        
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != maxima1 and b[i] != maxima1)
                return -1;
            
            if (a[i] != maxima1) {
                if (b[i] == maxima1) {
                    cnt1++;
                } else {
                    f = 1;
                    break;
                }
            }
        }
        
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != maxima2 and b[i] != maxima2)
                return -1;
            else {
                if (b[i] != maxima2) {
                    if (a[i] == maxima2) {
                        cnt2++;
                    } else {
                        f2 = 1;
                        break;
                    }
                }
            }
        }
        
        return min(cnt1, cnt2);
    }
};