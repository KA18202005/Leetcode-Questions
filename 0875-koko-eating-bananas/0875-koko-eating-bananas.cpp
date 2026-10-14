class Solution {
private:
    int findMax(vector<int> &v) {
        return *max_element(v.begin(), v.end()); 
    }

    int calculatetotalhours(vector<int> &v, int hourly) {
        int totalH = 0;
        for (int i = 0; i < v.size(); i++) {
            totalH += (v[i] + hourly - 1) / hourly; 
        }
        return totalH;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while (low < high) { 
            int mid = low + (high - low) / 2;
            int totalH = calculatetotalhours(piles, mid);
            if (totalH <= h) high = mid;  
            else low = mid + 1;
        }
        return low;
    }
};