class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool turn = true;
        while (n >= stones) {
            n -= stones;
            stones--;
            turn = !turn;
        }
        return !turn;
    }
};