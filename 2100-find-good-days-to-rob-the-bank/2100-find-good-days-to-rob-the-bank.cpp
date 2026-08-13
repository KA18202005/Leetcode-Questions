class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size(), cnt = 1;
        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = 1, suf[n - 1] = 1;
        for(int i = 1; i < n; i++) {
            if(security[i] <= security[i - 1]) cnt++;
            else cnt = 1;
            pre[i] = cnt;
        }
        cnt = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(security[i] <= security[i + 1]) cnt++;
            else cnt = 1;
            suf[i] = cnt;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(pre[i] - 1 >= time && suf[i] - 1 >= time) ans.push_back(i);
        }
        return ans;
    }
};