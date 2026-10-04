class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;
        stack<int> st;
        for (int num : nums2) {
            while (!st.empty() && num >= st.top()) {
                nge[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> ans;
        for (int num : nums1) {
            if (nge.count(num)) ans.push_back(nge[num]);
            else ans.push_back(-1);
        }
        return ans;
    }
};