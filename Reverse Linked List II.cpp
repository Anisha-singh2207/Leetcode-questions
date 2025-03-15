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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     if(!head && !head->next){
        return head;
     }

     //create new dummy node as head can be changed in this question
     ListNode* dummy=new ListNode(0);
     dummy->next=head;
     ListNode* prev=dummy;

     for(int i=1;i<left;i++){
        prev=prev->next;
     }
      
      ListNode* curr=prev->next;


      for(int i=1;i<=right-left;i++){
          ListNode* temp=prev->next;
        prev->next=curr->next;
        curr->next=curr->next->next;
        prev->next->next=temp;
      }
      return dummy->next;
        
    }
};