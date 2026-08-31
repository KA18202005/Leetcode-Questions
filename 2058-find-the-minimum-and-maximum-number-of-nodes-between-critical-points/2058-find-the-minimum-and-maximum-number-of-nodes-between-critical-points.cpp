/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ind;
        ListNode* prev = head;
        head = head->next;
        int i = 1;
        while(head->next != NULL) {
            if((prev->val < head->val && head->val > head->next->val) ||
               (prev->val > head->val && head->val < head->next->val)) {
                ind.push_back(i);
            }
            prev = head;
            head = head->next;
            i++;
        }
        if(ind.size() < 2) {
            return {-1, -1};
        }
        int mini = INT_MAX;
        int maxi = ind.back() - ind.front();
        for(int i = 0; i < ind.size() - 1; i++) {
            mini = min(mini, ind[i + 1] - ind[i]);
        }
        return {mini, maxi};
    }
};