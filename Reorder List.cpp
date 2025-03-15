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
 ListNode* reverseLL(ListNode* node) {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* last = reverseLL(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;

          ListNode* slow=head;
          ListNode* fast=head;
          while(fast && fast->next){
       slow=slow->next;
       fast=fast->next->next;
        }

        ListNode* rev=reverseLL(slow);
        ListNode* curr=head;
        while(rev->next!=NULL){
         ListNode* temp=curr->next;
         curr->next=rev;
         ListNode* temprev=rev->next;
         rev->next=temp;
         curr=temp;
         rev=temprev;
        }
    }
};