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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;

        while(h1 != nullptr && h2 != nullptr){
            int sum = h1->val + h2->val + carry;
            int to_add = sum;
            if(sum>9){
                to_add = sum%10;
                carry = sum/10;
            }
            else{
                carry=0;
            }
            ListNode* node = new ListNode(to_add);
            temp->next = node;
            temp = temp->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        while(h1 != nullptr && h2 == nullptr){
            int sum = h1->val + carry;
            int to_add = sum;
            if(sum>9){
                to_add = sum%10;
                carry = sum/10;
            }
            else{
                carry=0;
            }
            ListNode* node = new ListNode(to_add);
            temp->next = node;
            temp = temp->next;
            h1 = h1->next;
        }
        while(h1 == nullptr && h2 != nullptr){
            int sum = h2->val + carry;
            int to_add = sum;
            if(sum>9){
                to_add = sum%10;
                carry = sum/10;
            }
            else{
                carry=0;
            }
            ListNode* node = new ListNode(to_add);
            temp->next = node;
            temp = temp->next;
            h2 = h2->next;
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            temp->next = node;
        }
        return dummy->next;
    }
};