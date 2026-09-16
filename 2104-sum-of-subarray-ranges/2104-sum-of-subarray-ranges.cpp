class Solution {
private:
    vector<int> NSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> PSEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);
        long long total = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total += left * right * arr[i];
        }
        return total;
    }

    vector<int> NGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> PGEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge = NGE(arr);
        vector<int> pgee = PGEE(arr);
        long long total = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            total += left * right * arr[i];
        }
        return total;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};