class Solution {
public:
    double average(vector<int>& salary) {
        int mini = *min_element(salary.begin(), salary.end());
        int maxi = *max_element(salary.begin(), salary.end());
        double avg = 0.0;
        int n = salary.size();
        for(int i = 0; i < salary.size(); i++) {
            if(salary[i] == mini || salary[i] == maxi) n--;
            else avg += salary[i];
        }
        return avg / n;
    }
};