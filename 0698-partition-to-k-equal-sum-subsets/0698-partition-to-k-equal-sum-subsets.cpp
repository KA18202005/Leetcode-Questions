class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % k != 0) return false;
        int target = total / k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > target) return false;
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for(int mask = 0; mask < (1 << n); mask++) {
            if(dp[mask] == -1) continue;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) continue;
                int newSum = dp[mask] + nums[i];
                if(newSum > target) continue;
                int newMask = mask | (1 << i);
                if(newSum == target) dp[newMask] = 0;
                else dp[newMask] = newSum;
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};