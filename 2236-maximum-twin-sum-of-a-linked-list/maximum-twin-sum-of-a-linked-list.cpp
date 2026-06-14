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
    int pairSum(ListNode* head) {
        unordered_map<int, int> mp;
        int n=0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            n++;
        }
        temp = head;
        int x=0;
        int ans = 0;
        while(temp != NULL){
            if(x < n/2){
                mp[x] += temp->val;
                ans = max(ans, mp[x]);
            }
            else{
                mp[n-x-1] += temp->val;
                ans = max(ans, mp[n-x-1]);
            }
            x++;
            temp = temp->next;
        }
        return ans;
    }
};