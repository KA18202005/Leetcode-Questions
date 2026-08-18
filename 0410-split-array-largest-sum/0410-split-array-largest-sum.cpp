class Solution {
private:
    int countStudents(vector<int>& arr, int sum) {
        int n = arr.size();
        int array = 1;
        long long subarray = 0;
        for(int i = 0; i < n; i++) {
            if(subarray + arr[i] <= sum) {
                subarray += arr[i];
            }
            else {
                array++;
                subarray = arr[i];
            }
        }
        return array;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(nums, mid);
            if(students > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};