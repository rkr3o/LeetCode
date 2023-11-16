#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        pbds A;
        for(auto x : nums)
            A.insert(x);
        return *A.find_by_order(k-1);
    }
};