class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1, high = 65536;
        long long ans = INT_MIN;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long temp = (mid * (mid + 1)) / 2;
            if (temp > n) high = mid - 1;
            else {
                ans = max(ans, mid);
                low = mid + 1;
            }
        }
        return ans;
    }
};