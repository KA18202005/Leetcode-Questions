class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        bool isAsc = true;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] != (nums[i] + 1) % n) {
                isAsc = false;
                break;
            }
        }
        bool isDesc = true;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] != (nums[i] - 1 + n) % n) {
                isDesc = false;
                break;
            }
        }
        if(!isAsc && !isDesc) return -1;
        int ind = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                ind = i;
                break;
            }
        }
        int ans = INT_MAX;
        if(isAsc) ans = min(ans, min(ind, n - ind + 2));
        if(isDesc) ans = min(ans, min(n - ind, ind + 2));
        return ans;
    }
};