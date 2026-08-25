class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int i = 1;
        while (true) {
            int mul = i * k;
            if (s.find(mul) == s.end()) return mul;
            i++;
        }
    }
};