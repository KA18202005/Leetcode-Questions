class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;
        for(auto &e : reservedSeats)
            mp[e[0]].insert(e[1]);
        int ans = 2 * n;
        for(auto &[row, seats] : mp) {
            bool left = true, mid = true, right = true;
            for(int s : seats) {
                if(s>=2 && s<=5) left = false;
                if(s>=4 && s<=7) mid = false;
                if(s>=6 && s<=9) right = false;
            }
            int possible = 0;
            if(left) possible++;
            if(right) possible++;
            if(possible == 0 && mid) possible = 1;
            ans -= 2;
            ans += possible;
        }
        return ans;
    }
};