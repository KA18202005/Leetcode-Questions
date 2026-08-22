class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<int> available(m, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(seats[i][j] == '.') {
                    available[i] |= (1 << j);
                }
            }
        }
        int totalMasks = 1 << n;
        vector<vector<int>> valid(m);
        for(int i = 0; i < m; i++) {
            for(int mask = 0; mask < totalMasks; mask++) {
                if((mask & available[i]) != mask) continue;
                if(mask & (mask << 1)) continue;
                valid[i].push_back(mask);
            }
        }
        vector<int> dp(totalMasks, -1);
        for(int mask : valid[0]) {
            dp[mask] = __builtin_popcount(mask);
        }
        for(int row = 1; row < m; row++) {
            vector<int> next(totalMasks, -1);
            for(int current : valid[row]) {
                int students = __builtin_popcount(current);
                for(int previous : valid[row - 1]) {
                    if(current & (previous << 1)) continue;
                    if(current & (previous >> 1)) continue;
                    next[current] = max(next[current], dp[previous] + students);
                }
            }
            dp = next;
        }
        return *max_element(dp.begin(), dp.end());
    }
};