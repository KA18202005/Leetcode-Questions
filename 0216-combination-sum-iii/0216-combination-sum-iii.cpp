class Solution {
private:
    void findCombination(int ind, int target, int k, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {   
        if (target == 0) {
            if (ds.size() == k)
                ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue; // skip duplicates
            if (arr[i] > target) break; // pruning
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], k, arr, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr, ds;
        vector<vector<int>> ans;
        for (int i = 1; i <= 9; i++) arr.push_back(i);
        findCombination(0, n, k, arr, ans, ds);
        return ans;
    }
};
