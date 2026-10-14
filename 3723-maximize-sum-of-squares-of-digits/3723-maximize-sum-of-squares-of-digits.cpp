class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num * 9) return "";
        string res = "";
        for(int i = 0; i < num; i++) {
            int digit = min(9, sum);
            res += ('0' + digit);
            sum -= digit;
        }
        return res;
    }
};