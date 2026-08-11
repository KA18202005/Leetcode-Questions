class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, -1);
        for(int i = 0; i < s.size(); i++) freq[s[i] - 'a']++;
        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i] - 'a'] == 0) return i; 
        }
        return -1;
    }
};