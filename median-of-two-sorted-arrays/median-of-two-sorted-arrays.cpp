class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int>maxima;
        priority_queue<int,vector<int>,greater<int>>minima;
        vector<int>v1;
        for(auto x:nums1)v1.push_back(x);
        for(auto x:nums2)v1.push_back(x);
        for(auto num: v1)
        {
               if(maxima.empty() || num<=maxima.top())
                {
                    maxima.push(num);
                }
                else
                {
                    minima.push(num);
                }
        
                // Balance the heaps
                if (maxima.size() > minima.size() + 1) {
                    minima.push(maxima.top());
                    maxima.pop();
                } else if (minima.size() > maxima.size()) {
                    maxima.push(minima.top());
                    minima.pop();
                }
        }

        if(maxima.size()>minima.size())
        {
            return maxima.top();
        }
        return (maxima.top()+minima.top())/2.0;
    }
};