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
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse;
        vector<int> psee;
        nse = NSE(arr);
        psee = PSEE(arr);
        int total = 0, mod = (int)(1e9 + 7);
        for(int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1ll * arr[i]) % mod) % mod;
        }
        return total;
    }
};