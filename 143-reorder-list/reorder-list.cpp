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
    ListNode* reverse(ListNode* head){
        if(!head) return head;
        ListNode* temp = head;
        ListNode* nxt = nullptr;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr ){
            fast = fast->next->next;
            slow = slow->next;
        }
        // cout << slow->val;
        
        ListNode* t2 = slow->next;
        slow->next = nullptr;
        ListNode* head2 = reverse(t2);
        t2 = head2;
        ListNode* temp = head;
        // cout << " " << head2;

        ListNode* dummy = new ListNode(-1);
        while(temp != nullptr && t2 != nullptr){
            ListNode* nxt1 = temp->next;
            temp->next = t2;
            ListNode* nxt2 = t2->next;
            t2->next = nxt1;
            temp = nxt1;
            t2 = nxt2;
        }
    }
};