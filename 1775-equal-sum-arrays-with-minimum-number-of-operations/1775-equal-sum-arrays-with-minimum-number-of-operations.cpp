class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if(sum1 == sum2) return 0;
        if(sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }
        int diff = sum2 - sum1;
        vector<int> changes;
        for(int x : nums1) changes.push_back(6 - x);
        for(int x : nums2) changes.push_back(x - 1);
        sort(changes.rbegin(), changes.rend());
        int ans = 0;
        for(int change : changes) {
            diff -= change;
            ans++;
            if(diff <= 0) return ans;
        }
        return -1;
    }
};