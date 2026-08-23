class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = INT_MAX;
        set<int> st;
        for(int i = x; i < n; i++) {
            st.insert(nums[i - x]);
            auto it = st.lower_bound(nums[i]);
            if(it != st.end()) {
                ans = min(ans, abs(nums[i] - *it));
            }
            if(it != st.begin()) {
                --it;
                ans = min(ans, abs(nums[i] - *it));
            }
        }
        return ans;
    }
};