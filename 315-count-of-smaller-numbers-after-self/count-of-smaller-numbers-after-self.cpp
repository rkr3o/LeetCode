#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        ordered_set s;

        for (int i = n - 1; i >= 0; --i) {
            // counts[i] is the number of elements smaller than nums[i] to its right
            counts[i] = s.order_of_key(nums[i]);
            // Insert nums[i] into the ordered_set
            s.insert(nums[i]);
        }

        return counts;
    }
};