class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        int ans = 0, msb = 0;
        int m = n;
        while(m != 0) {
            msb++;
            m = m / 2;
        }
        ans = pow(2, msb) - 1;
        return ans + 1;
    }
};