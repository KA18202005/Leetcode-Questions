class Solution {
public:
    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;
        for(int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;
            bool overflow = false;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    bits++;
                    L = lcm(L, coins[i]);
                    if(L > x) {
                        overflow = true;
                        break;
                    }
                }
            }
            if(overflow) continue;
            if(bits % 2 == 1) ans += x / L;
            else ans -= x / L;
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while(low < high) {
            long long mid = low + (high - low) / 2;
            if(count(mid, coins) >= k) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};