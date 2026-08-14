class Solution {
    const long long MOD = 1e9 + 7;
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] + strength[i]) % MOD;
        }
        vector<long long> prefix2(n + 2, 0);
        for(int i = 0; i <= n; i++) {
            prefix2[i + 1] = (prefix2[i] + prefix[i]) % MOD;
        }
        vector<int> left(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && strength[st.top()] >= strength[i]) {
                st.pop();
            }
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int> right(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && strength[st.top()] > strength[i]) {
                st.pop();
            }
            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            long long rightSum = (prefix2[right[i] + 1] - prefix2[i + 1] + MOD) % MOD;
            rightSum = rightSum * leftCount % MOD;
            long long leftSum = (prefix2[i + 1] - prefix2[left[i] + 1] + MOD) % MOD;
            leftSum = leftSum * rightCount % MOD;
            long long total = (rightSum - leftSum + MOD) % MOD;
            ans = (ans + strength[i] * total) % MOD;
        }
        return ans;
    }
};