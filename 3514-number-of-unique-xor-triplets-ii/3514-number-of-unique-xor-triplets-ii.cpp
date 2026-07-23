class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        bool pairXor[2048] = {};
        bool ans[2048] = {};
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }
        for (int x = 0; x < 2048; x++) {
            if (!pairXor[x]) continue;
            for (int num : nums) {
                ans[x ^ num] = true;
            }
        }
        int cnt = 0;
        for (bool x : ans) cnt += x;
        return cnt;
    }
};