class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &a, vector<int> &b)
        {

            int n = a.size(), m = b.size();
            int total = n + m;
            int prev = 0, cur = 0;

            for (int k = 0, i = 0, j = 0; k <= total / 2; k++)
            {
                prev = cur;
                if (i < n && (j >= m || a[i] <= b[j]))
                {
                    cur = a[i++];
                }
                else
                {
                    cur = b[j++];
                }
            }

            if (total & 1)
            {
                return cur;
            }
            else
            {
                return (prev + cur) / 2.0;
            }
        }
};