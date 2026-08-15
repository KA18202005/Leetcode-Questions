class Solution {
private:
    unordered_map<int, bool> memo;
    int maxNum;
    int target;

    bool dfs(int mask, int sum) {
        if(memo.count(mask)) return memo[mask];
        for(int i = 1; i <= maxNum; i++) {
            if(mask & (1 << (i - 1))) continue;
            if(sum + i >= target) return memo[mask] = true;
            int newMask = mask | (1 << (i - 1));
            if(!dfs(newMask, sum + i)) {
                return memo[mask] = true;
            }
        }
        return memo[mask] = false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxNum = maxChoosableInteger;
        target = desiredTotal;
        int total = maxNum * (maxNum + 1) / 2;
        if(total < target) return false;
        if(maxNum >= target) return true;
        memo.clear();
        return dfs(0, 0);
    }
};