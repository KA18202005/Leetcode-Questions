class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for(int i = 0; i < s.size(); i++) {
            int m = 0;
            int index = 0;
            for(int j = i + 1; j < s.size(); j++) {
                if(m <= (s[j] - '0')) {
                    m = s[j] - '0';
                    index = j;
                }
            }
            if(m > (s[i] - '0')) {
                swap(s[i], s[index]);
                break;
            }
        }
        return stoi(s);
    }
};