class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for(char a = 'a'; a <= 'z'; a++) {
            for(char b = 'a'; b <= 'z'; b++) {
                if(a == b) continue;
                int countA = 0;
                int countB = 0;
                int remainingB = 0;
                for(char c : s) {
                    if(c == b) remainingB++;
                }
                for(char c : s) {
                    if(c == a) countA++;
                    if(c == b) {
                        countB++;
                        remainingB--;
                    }
                    if(countA > 0 && countB > 0) ans = max(ans, countA - countB);
                    if(countB > countA && remainingB > 0) {
                        countA = 0;
                        countB = 0;
                    }
                }
            }
        }
        return ans;
    }
};