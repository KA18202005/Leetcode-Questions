class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            int revIndex = ('z' - s[i]) + 1;
            int position = i + 1;
            sum += revIndex * position;
        }
        return sum;
    }
};