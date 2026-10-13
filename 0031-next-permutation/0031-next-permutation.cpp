class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if(ind != -1) {
            for(int i = n - 1; i >= ind; i--) {
                if(nums[i] > nums[ind]) {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
        }
        int s = ind + 1, e = n - 1;
        while(s < e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
};