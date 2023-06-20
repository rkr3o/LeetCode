class Solution
{
    public:
        bool backspaceCompare(string s, string t)
        {
            string res;
            for (auto &x: s)
            {
                if (x == '#' and !res.empty()) res.pop_back();
                else if (x == '#')continue;
                else res.push_back(x);
            }
            string res2;
            for (auto &x: t)
            {
                if (x == '#' and !res2.empty()) res2.pop_back();
                else if (x == '#')continue;
                else res2.push_back(x);
            }
            if (res.empty() and res2.empty()) return true;
            return res == res2;
        }
};