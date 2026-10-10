class Solution {
private:
    int findWays(vector<int> &nums, int tar) {
        int n = nums.size();
        vector<int> prev(tar + 1, 0);
        if (nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if (nums[0] != 0 && nums[0] <= tar) prev[nums[0]] = 1;
        for (int ind = 1; ind < n; ind++) {
            vector<int> cur(tar + 1, 0);
            for (int target = 0; target <= tar; target++) {
                int notTaken = prev[target];
                int taken = 0;
                if (nums[ind] <= target) taken = prev[target - nums[ind]];
                cur[target] = (notTaken + taken);
            }
            prev = cur;
        }
        return prev[tar];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }
        if (totSum - target < 0 || (totSum - target) % 2 != 0) return 0;
        return findWays(nums, (totSum - target) / 2);
    }
};