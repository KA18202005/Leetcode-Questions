class Solution {
private:
    int possible(vector<int> arr, int day, int k, int m) {
        int n = arr.size();
        int cnt = 0, noofB = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] <= day) {
                cnt++;
            }
            else {
                noofB += (cnt / k);
                cnt = 0;
            }
        }
        noofB += (cnt / k);
        return noofB >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        if(val > bloomDay.size()) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(possible(bloomDay, mid, k, m)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};