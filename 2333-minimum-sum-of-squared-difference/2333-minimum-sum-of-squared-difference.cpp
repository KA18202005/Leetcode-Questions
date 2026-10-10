
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> a(n);
        long long sum = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            a[i] = abs(nums1[i] - nums2[i]);
            sum += a[i];
            mx = max(mx, a[i]);
        }
        if (sum <= k) return 0;
        int l = 0, r = mx;
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long need = 0;
            for (int x : a) need += max(0, x - mid);
            if (need <= k) r = mid;
            else l = mid + 1;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            k -= max(0, a[i] - l);
            a[i] = min(a[i], l);
        }
        for (int i = 0; i < n && k > 0; i++) {
            if (a[i] == l && a[i] > 0) {
                a[i]--;
                k--;
            }
        }
        for (int x : a) ans += 1LL * x * x;
        return ans;
    }
};