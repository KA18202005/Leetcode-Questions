class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int len = s.size();
        int k = digits.size();
        int ans = 0;
        for(int length = 1; length < len; length++) {
            ans += pow(k, length);
        }
        for(int i = 0; i < len; i++) {
            bool found = false;
            for(string d : digits) {
                if(d[0] < s[i]) ans += pow(k, len - i - 1);
                else if(d[0] == s[i]) {
                    found = true;
                    break;
                }
            }
            if(!found) return ans;
        }
        return ans + 1;
    }
};