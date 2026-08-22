class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MIN, mindiff = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int diff = abs(0 - nums[i]);
            if(diff < mindiff) {
                ans = nums[i];
                mindiff = diff;
            }
            else if(diff == mindiff) {
                if(nums[i] > ans) ans = nums[i];
            }
        }
        return ans;
    }
};