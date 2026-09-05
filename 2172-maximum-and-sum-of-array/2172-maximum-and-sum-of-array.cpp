class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        int total = 1 << (2 * numSlots);
        vector<int> dp(total, -1);
        dp[0] = 0;
        for(int mask = 0; mask < total; mask++) {
            if(dp[mask] == -1) continue;
            int used = 0;
            for(int j = 0; j < numSlots; j++) {
                int cnt = (mask >> (2 * j)) & 3;
                used += cnt;
            }
            if(used == n) continue;
            for(int slot = 1; slot <= numSlots; slot++) {
                int cnt = (mask >> (2 * (slot - 1))) & 3;
                if(cnt < 2) {
                    int newMask = mask + (1 << (2 * (slot - 1)));
                    dp[newMask] = max(dp[newMask], dp[mask] + (nums[used] & slot));
                }
            }
        }
        int ans = 0;
        for(int x : dp) ans = max(ans, x);
        return ans;
    }
};