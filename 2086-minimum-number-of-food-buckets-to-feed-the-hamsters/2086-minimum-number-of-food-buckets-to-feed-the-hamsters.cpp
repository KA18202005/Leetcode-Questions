class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n = hamsters.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(hamsters[i] != 'H') continue;
            if(i > 0 && hamsters[i - 1] == 'B') continue;
            if(i + 1 < n && hamsters[i + 1] == '.') {
                hamsters[i + 1] = 'B';
                ans++;
            }
            else if(i > 0 && hamsters[i - 1] == '.') {
                hamsters[i - 1] = 'B';
                ans++;
            }
            else return -1;
        }
        return ans;
    }
};