class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2) return {};
		vector<long long> ans;
        long long i = 2;
        long long sum = 0;
        while((sum + i) <= finalSum){
            ans.push_back(i);
            sum += i;
            i += 2;
        }
		int sz = ans.size();
        ans[sz - 1] += (finalSum - sum);
        return ans;
    }
};