class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        long long ans = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] < sum) ans = nums[i] + sum;
            sum += nums[i];
        }
        return ans;
    }
};