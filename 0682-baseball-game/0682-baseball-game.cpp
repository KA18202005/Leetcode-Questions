class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        vector<int> ans;
        for(auto &c : operations) {
            if(c == "C") {
                ans.pop_back();
            }
            else if(c == "D") {
                int n = ans.size();
                ans.push_back(2 * ans[n - 1]);
            }
            else if(c == "+") {
                int n = ans.size();
                ans.push_back(ans[n - 1] + ans[n - 2]);
            }
            else ans.push_back(stoi(c));
        }
        for(int i = 0; i < ans.size(); i++) sum += ans[i];
        return sum;
    }
};