
class Solution
{
    public:
    int solve(vector<string> &garbage, vector<int> &time)
    {
        int cnt = 0;
        int n = time.size();
        for (int i = 1; i < n; ++i)
        {
            time[i] += time[i - 1];
        }
        //print(time);
        int m = -1, p = -1, g = -1;
        for (int i = 0; i < garbage.size(); ++i)
        {
            string t = garbage[i];
            cnt += t.size();
            for (auto x: t)
            {
                if (x == 'P') p = i;
                if (x == 'G') g = i;
                if (x == 'M') m = i;
            }
        }
        // print(time);
        // cout << cnt << endl;
        // cout << p << " " << m << " " << g << endl;
        if (p > 0) cnt += time[p - 1];
        if (g > 0) cnt += time[g - 1];
        if (m > 0) cnt += time[m - 1];
        return cnt;
    }
    int garbageCollection(vector<string> &garbage, vector<int> &time)
    {
        return solve(garbage, time);
    }
};