class Solution {
public:
    void insertPrimes(int n, unordered_map<int, int>& mp) {
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) mp[i]++;
            while(n % i == 0) n /= i;
        }
        if(n > 1) mp[n]++;
    }
    void removePrimes(int n, unordered_map<int, int>&mp) {
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                mp[i]--;
                if(mp[i] == 0) mp.erase(i);
            }
            while(n % i == 0) n /= i;
        }
        if(n > 1) {
            mp[n]--;
            if(mp[n] == 0) mp.erase(n);
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        int l = 0;
        unordered_map<int, int>mp;
        int ans = 0;
        for(int r = 0; r < nums.size(); r++){
            insertPrimes(nums[r], mp);
            while(mp.size() > k) {
                removePrimes(nums[l], mp);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};