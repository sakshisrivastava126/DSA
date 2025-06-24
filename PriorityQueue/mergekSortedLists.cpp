#include <queue>
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

//min heap
 struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return NULL;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

//we pushed all the heads of LLs we have 
        int n = lists.size();
        for(int i=0; i<n; i++){
            if(lists[i] != nullptr){
                pq.push(lists[i]);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

//what we are basically doing is we are comparing heads of the LL 
//and if we use a head then we add(replace) head->next in our pq
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if(curr->next != nullptr) pq.push(curr->next);
        }

        return dummy.next;
    }
};
