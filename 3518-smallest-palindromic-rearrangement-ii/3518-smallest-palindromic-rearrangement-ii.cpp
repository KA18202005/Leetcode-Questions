class Solution {
    const int INF = 1000001; // Slightly larger than max k (10^6)

    // Compute nCr on the fly in O(min(r, n-r)) time
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        if (r == 0) return 1;
        
        // C(24, 12) = 2,704,156 > 10^6. 
        // Any combination with min(r, n-r) >= 12 is guaranteed to exceed INF.
        if (r >= 12) return INF; 
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res > INF) return INF;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        // 1. Count frequencies of each character
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // 2. Determine half frequencies and the middle character (if odd length)
        vector<int> f(26, 0);
        int m = 0;
        string mid_char = "";
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                mid_char += (char)('a' + i);
            }
            f[i] = count[i] / 2;
            m += f[i];
        }
        
        // Helper lambda to calculate permutations of a multiset
        auto countWays = [&](const vector<int>& freq) -> long long {
            long long total = 1;
            int len = 0;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] == 0) continue;
                len += freq[i];
                total = total * nCr(len, freq[i]);
                if (total > INF) total = INF;
            }
            return total;
        };
        
        // 3. Check if total permutations are fewer than k
        if (countWays(f) < k) {
            return "";
        }
        
        // 4. Greedily build the first half
        string half = "";
        for (int step = 0; step < m; ++step) {
            for (int c = 0; c < 26; ++c) {
                if (f[c] == 0) continue;
                
                f[c]--; // Temporarily use character 'a' + c
                long long ways = countWays(f);
                
                if (ways >= k) {
                    half += (char)('a' + c);
                    break; // Move to the next position
                } else {
                    k -= ways;
                    f[c]++; // Restore frequency and try next character
                }
            }
        }
        
        // 5. Assemble the full palindrome
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        
        return half + mid_char + rev_half;
    }
};