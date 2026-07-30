class Solution {
public:
    int minimumPushes(string word) {
        auto [q, r] = div(word.size(), 8);
        return ((q << 2) + r) * (q + 1);
    }
};