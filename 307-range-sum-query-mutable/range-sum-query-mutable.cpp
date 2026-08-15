class segmentTree {
public:
    vector<int> seg;
    segmentTree(int n) { seg.resize(4 * n + 1); }

    void build(int ind, int low, int high, vector<int>& nums) {
        if (low == high) {
            seg[ind] = nums[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, nums);
        build(2 * ind + 2, mid + 1, high, nums);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int sumQuery(int ind, int low, int high, int l, int r) {
        if (high < l || low>r) {
            return 0;
        }

        if ( low>=l && high<=r) {
            return seg[ind];
        }

        int mid = (low + high) / 2;
        int leftSum = sumQuery(2 * ind + 1, low, mid, l, r);
        int rightSum = sumQuery(2 * ind + 2, mid+1, high, l, r);
        return leftSum + rightSum;
    }

    void up(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid) {
            up(2 * ind + 1, low, mid, i, val);
        } else {
            up(2 * ind + 2, mid + 1, high, i, val);
        }
        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }
};

class NumArray {
public:
    segmentTree* sg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        sg = new segmentTree(n);
        sg->build(0, 0, n - 1, nums);
    }

    void update(int index, int val) { sg->up(0, 0, n - 1, index, val); }

    int sumRange(int left, int right) {
        return sg->sumQuery(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */