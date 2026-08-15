class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0, cnt = 0, zero = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) zero++;
            xorr ^= nums[i];
        }
        if(zero == nums.size()) cnt = 0;
        else if(xorr == 0) cnt = nums.size() - 1;
        else cnt = nums.size();
        return cnt;
    }
};