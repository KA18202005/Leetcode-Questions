class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<int> freq(26, 0);
        for(char c : text) freq[c - 'a']++;
        int ans = 0;
        int i = 0;
        while(i < n) {
            int j = i;
            while(j < n && text[j] == text[i]) j++;
            int left = j - i;
            ans = max(ans, min(left + 1, freq[text[i] - 'a']));
            int k = j + 1;
            if(k < n) {
                while(k < n && text[k] == text[i]) k++;
                int right = k - (j + 1);
                if(j < n && text[j] != text[i]) {
                    ans = max(ans, min(left + right + 1, freq[text[i] - 'a']));
                }
            }
            i = j;
        }
        return ans;
    }
};