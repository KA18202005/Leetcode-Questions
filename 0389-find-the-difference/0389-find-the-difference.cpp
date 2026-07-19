class Solution {
public:
    char findTheDifference(string s, string t) {
        int num1 = 0, num2 = 0;
        for(int i = 0; i < s.size(); i++) {
            num1 += s[i] - 'a';
        }
        for(int i = 0; i < t.size(); i++) {
            num2 += t[i] - 'a';
        }
        char c = 'a' + (num2 - num1);
        return c;
    }
};