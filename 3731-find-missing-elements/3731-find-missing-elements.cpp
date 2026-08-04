class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int small = *min_element(nums.begin(), nums.end());
        int large = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        unordered_set<int> st(nums.begin(), nums.end());
        for(int i = small; i <= large; i++) {
            if(st.find(i) == st.end()) ans.push_back(i);
        }
        return ans;
    }
};