class Solution {
private:
    void combination(int ind, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds) {
        if(ind == arr.size()) {
            if(target == 0) ans.push_back(ds);
            return;
        }
        if(arr[ind] <= target) {
            ds.push_back(arr[ind]);
            combination(ind, arr, target - arr[ind], ans, ds);
            ds.pop_back();
        }
        combination(ind + 1, arr, target, ans, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combination(0, candidates, target, ans, ds);
        return ans;
    }
};