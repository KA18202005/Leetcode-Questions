class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int same = 0;
        for(auto &p : points) {
            int dx = p[0] - location[0];
            int dy = p[1] - location[1];
            if(dx == 0 && dy == 0) same++;
            else {
                double a = atan2(dy, dx) * 180.0 / M_PI;
                if(a < 0) a += 360;
                angles.push_back(a);
            }
        }
        sort(angles.begin(), angles.end());
        int n = angles.size();
        for(int i = 0; i < n; i++) {
            angles.push_back(angles[i] + 360);
        }
        int ans = 0;
        int left = 0;
        for(int right = 0; right < 2 * n; right++) {
            while(angles[right] - angles[left] > angle + 1e-9) {
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans + same;
    }
};