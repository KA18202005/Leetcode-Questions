class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = false;
        int s = nums1[0];
        for(int n : nums1) {
            if(n < s) s = n;
            if(n & 1) odd = true;
        }
        if(s & 1) return true;
        return !odd;
    }
};