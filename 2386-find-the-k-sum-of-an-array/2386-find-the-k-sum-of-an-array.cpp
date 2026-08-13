class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long maxSum = 0;
        for (int x : nums) {
            if (x > 0) maxSum += x;
        }
        for (int& x : nums) x = abs(x);
        sort(nums.begin(), nums.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        for (int cnt = 1; cnt < k; cnt++) {
            auto [sum, i] = pq.top();
            pq.pop();
            if (i < nums.size()) {
                pq.push({sum + nums[i], i + 1});
                if (i > 0) pq.push({sum + nums[i] - nums[i - 1], i + 1});
            }
        }
        return maxSum - pq.top().first;
    }
};