class Solution {
public:
    long long appealSum(string s) {
        vector<int> last(26, -1);
        long long total = 0;
        long long curr = 0;
        for (int i = 0; i < s.size(); ++i) {
            int ch = s[i] - 'a';
            curr += i - last[ch];
            last[ch] = i;
            total += curr;
        }
        return total;
    }
};