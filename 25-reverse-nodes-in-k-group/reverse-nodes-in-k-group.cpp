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
        ListNode* temp = head; 
        ListNode* nxt = temp->next;
        ListNode* prev = nullptr;

        while(temp != NULL){
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        } 
        return prev;
    }
    ListNode* findNode(ListNode* head, int k){
        ListNode* temp = head;
        while(temp != NULL && k>1){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nxt = temp->next;
        ListNode* prev = nullptr;
        ListNode* kth = nullptr;

        while(temp != NULL){
            kth = findNode(temp, k);

            if(kth == nullptr){
                if(prev) prev->next = temp;
                return head;
            }

            nxt = kth->next;
            kth->next = nullptr;

            ListNode* newHead = reverse(temp);

            if(temp==head){
                head = newHead;
            }
            else{
                prev->next = newHead;
            }
            prev = temp;
            temp = nxt;
        }
        return head;
    }
};