class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if (n == 0) return "";
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }
        if (pq.top().first > (n + 1) / 2) return "";

        string result = "";
        pair<int, char> prev = {0, '#'};
        while (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            pq.pop();
            result += ch;
            cnt--;
            if (prev.first > 0) pq.push(prev);
            prev = {cnt, ch};
        }

        return result;
    }
};