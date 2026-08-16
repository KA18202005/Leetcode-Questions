class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        for(int i = 0; i < n; i++) stones[i] = stones[i] % 3;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(stones[i] == 0) cnt0++;
            else if(stones[i] == 1) cnt1++;
            else cnt2++;
        }
        if(cnt0 % 2 == 0) {
            if(cnt1 != 0 && cnt2 != 0) return true;
        }
        if(cnt0 % 2 != 0) {
            if(abs(cnt1 - cnt2) >= 3) return true;
        }
        return false;
    }
};