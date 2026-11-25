class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        const long long mod = 1000000007LL;
        const long long base = 911382323LL;
        vector<long long> powv(n + 1, 1), h(n + 1, 0);
        for (int i = 1; i <= n; i++) powv[i] = (powv[i - 1] * base) % mod;
        for (int i = 0; i < n; i++) h[i + 1] = (h[i] * base + nums[i]) % mod;
        auto getHash = [&](int l, int r) { // [l, r)
            long long x = (h[r] - h[l] * powv[r - l]) % mod;
            if (x < 0) x += mod;
            return x;
        };
        auto hasUnique = [&](int len) {
            unordered_map<long long, int> cnt;
            cnt.reserve(n);
            for (int i = 0; i + len <= n; i++) {
                long long hv = getHash(i, i + len);
                cnt[hv]++;
            }
            for (auto &p : cnt) if (p.second == 1) return true;
            return false;
        };
        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};