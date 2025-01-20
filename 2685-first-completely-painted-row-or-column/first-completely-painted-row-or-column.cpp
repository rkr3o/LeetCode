class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();  
        int x = arr.size();

        map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(n, m);
        vector<int> col(m, n);

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [r, c] = mp[num];

            row[r]--;
            col[c]--;

            if (row[r] == 0 || col[c] == 0) {
                return i;
            }
        }

        return -1;
    }
};
