class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<long long>pref(m,0);
        vector<long long>suff(m,0);
        long long sum = 0 ;
        for(int i = 0 ; i < m; i++){
            sum+=grid[0][i];
            pref[i]=sum;
        }
        sum = 0;
        for(int i = m-1 ; i>=0 ; i--){
            sum+=grid[1][i];
            suff[i] = sum;
        }

        long long second_maxima = LLONG_MAX;
        for(int i=0;i<m;i++){
            long long up = pref[m-1]-pref[i];
            long long down=suff[0]-suff[i];
            long long val=max(up,down);
            second_maxima=min(second_maxima, val);
        }
        return second_maxima;
    }
};