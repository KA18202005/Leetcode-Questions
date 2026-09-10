class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> freq(101, -1);
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) freq[nums[i]]++;
        for(int i = 1; i <= 100; i++) {
            if(freq[i] != -1) cnt++;
        }
        return cnt;
    }
};