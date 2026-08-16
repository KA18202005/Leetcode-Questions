class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i < n; i++) {
            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            pq.push({dist, {points[i][0], points[i][1]}});
        }
        while(k != 0) {
            auto it = pq.top();
            pq.pop();
            ans.push_back({it.second.first, it.second.second});
            k--;
        }
        return ans;
    }
};