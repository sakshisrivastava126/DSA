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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int count=1;
        ListNode* prev = nullptr;
        ListNode* lastNode = nullptr;
        ListNode* newHead = nullptr;

        if(head == NULL || head->next == NULL || k==0) return head;
        
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        lastNode = temp;
        temp->next = head;
        temp = head;
        for(int i=0; i<abs(count-(k%count)); i++){
            prev = temp;
            temp = temp->next;
        }
        newHead = temp;
        prev->next = NULL;
        return newHead;
    }
};