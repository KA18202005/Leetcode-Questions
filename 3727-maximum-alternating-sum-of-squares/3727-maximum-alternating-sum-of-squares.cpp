class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) nums[i] *= -1;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(i < n / 2) score -= nums[i] * nums[i];
            else score += nums[i] * nums[i];
        }
        return score;
    }
};