class NumArray {
public:
    const int MAXN = 3e6 + 10;
    vector<int> arr;
    vector<int> seg;
    public:
    void update(int ind, int low, int high, int node, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        } else {
            int mid = (low + high) / 2;
            if (node >= low && node <= mid) {
                update(2 * ind + 1, low, mid, node, val);
            } else {
                update(2 * ind + 2, mid + 1, high, node, val);
            }
            seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
        }
    }

    int query(int ind, int low, int high, int l, int r) {
        if (low >= l && high <= r)
            return seg[ind];
        if (high < l || low > r)
            return 0;
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    void build(int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    NumArray(vector<int>& nums) {
        arr = nums;
        seg.resize(4 * MAXN);
        build(0, 0, nums.size() - 1);
    }

    void update(int index, int val) {
        update(0, 0, arr.size() - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, arr.size() - 1, left, right);
    }
};

// Example usage:
// vector<int> nums = {1, 3, 5};
// NumArray* obj = new NumArray(nums);
// obj->update(index, val);
// int param_2 = obj->sumRange(left, right);
