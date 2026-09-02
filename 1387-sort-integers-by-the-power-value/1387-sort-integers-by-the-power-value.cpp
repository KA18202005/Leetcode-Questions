class Solution {
private:
    int power(int n){
        int cnt = 0;
        while(n != 1) {
            if(n % 2 == 0) n = n / 2;
            else n = 3 * n + 1;
            cnt++;
        }
        return cnt;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> mpp;
        for(int i = lo; i <= hi; i++) {
            mpp.push_back({power(i), i});
        }
        sort(mpp.begin(), mpp.end());
        return mpp[k - 1].second;
    }
};