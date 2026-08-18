class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int j = 0;
        int n = passengers.size();
        int ans = 0;
        for(int i = 0; i < buses.size(); i++) {
            int count = 0;
            while(j < n && passengers[j] <= buses[i] && count < capacity) {
                j++;
                count++;
            }
            if(i == buses.size() - 1) {
                if(count < capacity) {
                    ans = buses[i];
                }
                else {
                    ans = passengers[j - 1] - 1;
                }
                while(binary_search(passengers.begin(), passengers.end(), ans)) {
                    ans--;
                }
            }
        }
        return ans;
    }
};