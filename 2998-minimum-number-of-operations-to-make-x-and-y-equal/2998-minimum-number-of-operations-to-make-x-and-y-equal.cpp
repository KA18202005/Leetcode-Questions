class Solution {
public:
    unordered_map<int,int>mp;
    int f(int x, int y) {
        if(x <= y) return y - x;
        if(mp.count(x)) return mp[x];
        int ans = x - y;
        int a1 = x - (x%5);
        int a2 = x+5 - (x%5);
        int a3 = x - (x%11);
        int a4 = x+11 - (x%11);
        ans = min(ans, abs(x-a1) + 1 + f(a1/5,y));
        ans = min(ans, abs(x-a2) + 1 + f(a2/5,y));
        ans = min(ans, abs(x-a3) + 1 + f(a3/11,y));
        ans = min(ans, abs(x-a4) + 1 + f(a4/11,y));
        return mp[x] = ans;
    }
    int minimumOperationsToMakeEqual(int x,int y){
        return f(x,y);
    }
};