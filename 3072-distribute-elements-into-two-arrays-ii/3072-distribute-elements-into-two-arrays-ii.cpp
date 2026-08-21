class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        int m = sorted.size();

        vector<int> bit1(m + 1, 0);
        vector<int> bit2(m + 1, 0);

        vector<int> a, b;

        a.push_back(nums[0]);
        b.push_back(nums[1]);

        auto update = [&](vector<int>& bit, int idx) {
            while(idx <= m) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](vector<int>& bit, int idx) {
            int sum = 0;
            while(idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        };

        auto getIndex = [&](int x) {
            return lower_bound(sorted.begin(), sorted.end(), x)
                   - sorted.begin() + 1;
        };

        update(bit1, getIndex(nums[0]));
        update(bit2, getIndex(nums[1]));

        for(int i = 2; i < n; i++) {

            int idx = getIndex(nums[i]);

            // Number of elements <= nums[i]
            int leA = query(bit1, idx);
            int leB = query(bit2, idx);

            // Number of elements > nums[i]
            int greaterA = a.size() - leA;
            int greaterB = b.size() - leB;

            if(greaterA > greaterB) {
                a.push_back(nums[i]);
                update(bit1, idx);
            }
            else if(greaterB > greaterA) {
                b.push_back(nums[i]);
                update(bit2, idx);
            }
            else {
                if(a.size() <= b.size()) {
                    a.push_back(nums[i]);
                    update(bit1, idx);
                }
                else {
                    b.push_back(nums[i]);
                    update(bit2, idx);
                }
            }
        }

        for(int x : b)
            a.push_back(x);

        return a;
    }
};