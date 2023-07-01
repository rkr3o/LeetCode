class Solution
{
    public:
        void setZeroes(vector<vector < int>> &v)
        {
            int n = v.size();
            int m = v[0].size();
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (v[i][j] == 0)
                    {
                        int ind = i - 1;
                        while (ind >= 0)
                        {
                            if (v[ind][j] != 0)
                            {
                                v[ind][j] = 1e9 + 10;
                            }
                            ind--;
                        }
                        ind = i + 1;
                        while (ind < n)
                        {
                            if (v[ind][j] != 0)
                            {
                                v[ind][j] = 1e9 + 10;
                            }
                            ind++;
                        }
                        ind = j - 1;
                        while (ind >= 0)
                        {
                            if (v[i][ind] != 0)
                            {
                                v[i][ind] = 1e9 + 10;
                            }
                            ind--;
                        }
                        ind = j + 1;
                        while (ind < m)
                        {
                            if (v[i][ind] != 0)
                            {
                                v[i][ind] = 1e9 + 10;
                            }
                            ind++;
                        }
                    }
                }
            }
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; j++)
                {
                    if (v[i][j] == 1e9 + 10)
                    {
                        v[i][j] = 0;
                    }
                }
            }
        }
};