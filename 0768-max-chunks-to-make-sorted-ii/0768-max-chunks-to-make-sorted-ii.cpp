class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffixMin(n);
        suffixMin[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(arr[i], suffixMin[i + 1]);
        }
        int ans = 0;
        int prefixMax = INT_MIN;
        for(int i = 0; i < n - 1; i++) {
            prefixMax = max(prefixMax, arr[i]);
            if(prefixMax <= suffixMin[i + 1]) ans++;
        }
        return ans + 1;
    }
};