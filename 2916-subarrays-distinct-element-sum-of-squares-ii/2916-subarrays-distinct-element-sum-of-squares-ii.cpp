class Solution {
public:
    static const int MOD = 1000000007;

    struct Node {
        long long sum = 0;
        long long sumSquares = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        long long oldSum = tree[node].sum;

        tree[node].sumSquares =
            (tree[node].sumSquares
             + 2LL * val % MOD * oldSum % MOD
             + len % MOD * val % MOD * val % MOD) % MOD;

        tree[node].sum =
            (oldSum + len * val) % MOD;

        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) {
            return;
        }

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum =
            (tree[node * 2].sum +
             tree[node * 2 + 1].sum) % MOD;

        tree[node].sumSquares =
            (tree[node * 2].sumSquares +
             tree[node * 2 + 1].sumSquares) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return;
        }

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        pull(node);
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.assign(4 * n + 5, Node());

        unordered_map<int, int> lastSeen;
        long long answer = 0;

        for (int i = 0; i < n; i++) {
            int previous = -1;

            if (lastSeen.count(nums[i])) {
                previous = lastSeen[nums[i]];
            }

            update(1, 0, n - 1, previous + 1, i);

            answer = (answer + tree[1].sumSquares) % MOD;

            lastSeen[nums[i]] = i;
        }

        return static_cast<int>(answer);
    }
};