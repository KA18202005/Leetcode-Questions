class Solution {
    static const int mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> power(n, 1);
        for(int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        int low = 0, high = n - 1;
        while(low <= high) {
            if(nums[low] + nums[high] <= target) {
                ans = (ans + power[high - low]) % mod;
                low++;
            }
            else high--;
        }
        return ans;
    }
};