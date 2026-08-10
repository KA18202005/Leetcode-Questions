/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if (a[i] == b[i]) cnt++;
        }
        return cnt;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        while (words.size() > 1) {
            int bestIndex = 0;
            int bestWorst = INT_MAX;
            for (int i = 0; i < words.size(); i++) {
                vector<int> count(7, 0);
                for (int j = 0; j < words.size(); j++) {
                    int same = match(words[i], words[j]);
                    count[same]++;
                }
                int worst = 0;
                for (int x : count) worst = max(worst, x);
                if (worst < bestWorst) {
                    bestWorst = worst;
                    bestIndex = i;
                }
            }
            string guess = words[bestIndex];
            int x = master.guess(guess);
            if (x == 6) return;
            vector<string> next;
            for (string word : words) {
                if (match(guess, word) == x) next.push_back(word);
            }
            words = next;
        }
        if (!words.empty()) master.guess(words[0]);
    }
};