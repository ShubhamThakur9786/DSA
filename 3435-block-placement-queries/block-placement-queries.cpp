class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * (n + 1), 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n, idx, val);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        return max(
            query(2 * node, start, mid, l, r),
            query(2 * node + 1, mid + 1, end, l, r)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXX = 50000;

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(MAXX);

        // Add all obstacles first
        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        SegmentTree seg(MAXX);

        // Build initial gaps
        auto it = obstacles.begin();
        int previous = *it;
        ++it;

        while (it != obstacles.end()) {
            seg.update(*it, *it - previous);
            previous = *it;
            ++it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                --it;

                int p = *it;

                int bestGap = seg.query(0, p);
                int tail = x - p;

                ans.push_back(max(bestGap, tail) >= sz);
            } else {
                int cur = q[1];

                auto it = obstacles.find(cur);

                int nxt = *std::next(it);
                int prv = *std::prev(it);

                seg.update(nxt, nxt - prv);

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};