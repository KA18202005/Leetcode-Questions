class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int x1 = coordinates[0][0], x2 = coordinates[1][0];
        int y1 = coordinates[0][1], y2 = coordinates[1][1];
        if (x1 == x2) {
            for (int i = 2; i < n; i++) {
                if (coordinates[i][0] != x1) return false;
            }
            return true;
        }
        double m = (double)(y2 - y1) / (x2 - x1);
        for (int i = 2; i < n; i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            double y_ex = y1 + m * (x - x1);
            if (y_ex != y) return false;
        }
        return true;
    }
};