class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //If you sort the array, the first and last strings will have the maximum difference
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs.back();
        int i = 0;
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }
        return first.substr(0, i);
    }
};