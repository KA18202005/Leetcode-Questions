class Solution {
public:
    int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
        long long sum = 0;
        int i = 0;
        int n = times.size();
        deque<int> d;
        for (int j = 0; j < n; j++) {
            sum += costs[j];
            while (!d.empty() && times[d.back()] <= times[j]) d.pop_back();
            d.push_back(j);
            if (times[d.front()] + 1LL * (j - i + 1) * sum > budget) {
                if (d.front() == i) d.pop_front();
                sum -= costs[i++];
            }
        }
        return n - i;
    }
};