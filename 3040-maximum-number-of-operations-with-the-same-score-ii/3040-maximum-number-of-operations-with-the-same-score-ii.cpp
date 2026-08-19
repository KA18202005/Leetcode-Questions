class Solution {
public:
    int dp[2000][2000];
    int solve(vector<int>& nums, int l, int r, int target) {
        if(l >= r) return 0;
        int &ans = dp[l][r];
        if(ans != -1) return ans;
        ans = 0;
        if(nums[l] + nums[l + 1] == target) {
            ans = max(ans, 1 + solve(nums, l + 2, r, target));
        }
        if(nums[r - 1] + nums[r] == target) {
            ans = max(ans, 1 + solve(nums, l, r - 2, target));
        }
        if(nums[l] + nums[r] == target) {
            ans = max(ans, 1 + solve(nums, l + 1, r - 1, target));
        }
        return ans;
    }

    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        ans = max(ans, 1 + solve(nums, 2, n - 1, nums[0] + nums[1]));
        memset(dp, -1, sizeof(dp));
        ans = max(ans, 1 + solve(nums, 0, n - 3, nums[n - 2] + nums[n - 1]));
        memset(dp, -1, sizeof(dp));
        ans = max(ans, 1 + solve(nums, 1, n - 2, nums[0] + nums[n - 1]));
        return ans;
    }
};