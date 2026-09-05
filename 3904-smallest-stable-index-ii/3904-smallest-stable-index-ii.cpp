class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = -1;
        int cand = 0, cmax = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            if (cand == i) cmax = maxi;
            if (nums[i] < cmax - k) cand = i + 1;
        }
        if (cand < nums.size()) return cand;
        return -1;
    }
};