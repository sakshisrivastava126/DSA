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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* temp = head;
        int cnt=0;
        while(temp){
            cnt++;
            temp = temp->next;
        }

        if(cnt==n){
            ListNode* dlt = head;
            head = dlt->next;
            delete dlt;
            return head;
        }

        int idx = cnt-n;
        temp = head;
        for(int i=1; i<idx; i++){
            temp = temp->next;
        }
        ListNode* dlt = temp->next;
        temp->next = dlt->next;
        delete dlt;

        return head;
    }
};