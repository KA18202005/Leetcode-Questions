class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxcnt = 0;
        for(auto& it: s) {
            if(it == '('){
                cnt++;
                maxcnt = max(maxcnt, cnt);
            } 
            else if(it == ')') {
                cnt--;
            }
            else continue;
        }
        return maxcnt;
    }
};