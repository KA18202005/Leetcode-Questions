class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> st;
        for(int i = 0; i < k; i++) st.insert(i);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> busy;
        vector<int> count(k, 0);
        for(int i = 0; i < n; i++) {
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                int server = busy.top().second;
                busy.pop();
                st.insert(server);
            }
            if(st.empty()) continue;
            int start = i % k;
            auto it = st.lower_bound(start);
            if(it == st.end()) it = st.begin();
            int server = *it;
            st.erase(it);
            busy.push({arrival[i] + load[i], server});
            count[server]++;
        }
        int maxi = 0;
        for(int x : count) maxi = max(maxi, x);
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) ans.push_back(i);
        }
        return ans;
    }
};