class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mini, maxi, ans;
        mini = min(need1, need2);
        maxi = max(need1, need2);
        ans = (long long) need1 * cost1 + (long long) need2 * cost2;
        ans  = min(ans, (long long)mini * costBoth + (long long) (need1 - mini) * cost1 + (long long) (need2 - mini) * cost2);
        ans = min(ans, (long long) maxi * costBoth);
        return ans;
    }
};