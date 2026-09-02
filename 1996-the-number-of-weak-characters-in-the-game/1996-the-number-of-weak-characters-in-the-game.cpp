class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](auto &a, auto &b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        int maxi = 0;
        int ans = 0;
        for(int i = 0; i < properties.size(); i++) {
            if(properties[i][1] < maxi) ans++;
            maxi = max(maxi, properties[i][1]);
        }
        return ans;
    }
};