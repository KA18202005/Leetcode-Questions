class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int x : rolls) {
            sum += x;
        }
        int total = mean * (m + n);
        int missingSum = total - sum;
        if(missingSum < n || missingSum > 6 * n) {
            return {};
        }
        vector<int> ans(n, 1);
        int remaining = missingSum - n;
        for(int i = 0; i < n && remaining > 0; i++) {
            int add = min(5, remaining);
            ans[i] += add;
            remaining -= add;
        }
        return ans;
    }
};