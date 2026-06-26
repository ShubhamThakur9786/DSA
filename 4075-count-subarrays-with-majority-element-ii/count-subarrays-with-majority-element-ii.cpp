class BIT {
public:
    vector<int> tree;
    int n;

    BIT(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        BIT bit(2 * n + 5);

        // Shift prefix sums to make indices positive
        int pref = n + 2;

        bit.update(pref, 1);

        long long ans = 0;

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            ans += bit.query(pref - 1);

            bit.update(pref, 1);
        }

        return ans;
    }
};