class Solution {
public:
    int maxProduct(int n) {
        int ans = 1;
        vector<int> freq(10, 0);
        while(n != 0) {
            int num = n % 10;
            freq[num]++;
            n = n / 10;
        }
        int cnt = 0;
        for(int i = 9; i >= 0; i--) {
            while (freq[i] > 0 && cnt < 2) {
                ans *= i;
                freq[i]--;
                cnt++;
            }
        }
        return ans;
    }
};