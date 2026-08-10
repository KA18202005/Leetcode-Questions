class Solution {
    vector<int> arr;

public:
    Solution(vector<int>& nums) {
        arr = nums;
    }

    vector<int> reset() {
        return arr;
    }

    vector<int> shuffle() {
        vector<int> temp = arr;
        for (int i = temp.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(temp[i], temp[j]);
        }
        return temp;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */