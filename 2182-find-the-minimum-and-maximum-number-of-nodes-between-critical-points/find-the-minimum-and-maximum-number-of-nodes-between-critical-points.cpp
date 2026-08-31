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
        vector<int> idx;
        ListNode* prev = NULL;
        ListNode* nxt = head->next;
        ListNode* temp = head;
        int cnt=0;
        while(temp->next != NULL){
            nxt = temp->next;
            if(prev && ((prev->val>temp->val && temp->val<nxt->val) || (prev->val < temp->val && nxt->val < temp->val))) idx.push_back(cnt);
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        if(idx.size() < 2) return {-1, -1};

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=1; i<idx.size(); i++){
            mini = min(mini, idx[i]-idx[i-1]);
        } 
        maxi = idx[idx.size()-1] - idx[0];
        return {mini, maxi};
    }
};