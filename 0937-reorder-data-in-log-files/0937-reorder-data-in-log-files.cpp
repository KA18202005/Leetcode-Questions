class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters;
        vector<string> digits;
        for(string log : logs) {
            int i = 0;
            while(log[i] != ' ') {
                i++;
            }
            if(isdigit(log[i + 1])) digits.push_back(log);
            else letters.push_back(log);
        }
        sort(letters.begin(), letters.end(),
            [](string &a, string &b) {
                int i = a.find(' ');
                int j = b.find(' ');
                string contentA = a.substr(i + 1);
                string contentB = b.substr(j + 1);
                if(contentA == contentB) {
                    return a.substr(0, i) < b.substr(0, j);
                }
                return contentA < contentB;
            }
        );
        for(string log : digits) {
            letters.push_back(log);
        }
        return letters;
    }
};