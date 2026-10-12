class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string repeated = A;
        int count = 1;
        // Keep repeating A until length >= B
        while (repeated.size() < B.size()) {
            repeated += A;
            count++;
        }
        // Case 1: B is already a substring
        if (repeated.find(B) != string::npos)
            return count;
        // Case 2: B spans across the boundary (need one more A)
        repeated += A;
        if (repeated.find(B) != string::npos
            return count + 1;
        // Case 3: Not possible
        return -1;
    }
};