class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int ans = 0;
        for (int x : nums) {
            if (x == 0) {
                pos = 0;
                neg = 0;
            }
            else if (x > 0) {
                pos = pos + 1;
                if (neg > 0) neg = neg + 1;
            }
            else {
                int oldPos = pos;
                int oldNeg = neg;
                if (oldNeg > 0) pos = oldNeg + 1;
                else pos = 0;
                neg = oldPos + 1;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};