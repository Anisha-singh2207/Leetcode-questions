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
int getLengthOfLL(ListNode* head){
    int l=0;
    ListNode* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L=getLengthOfLL(head);

        if(L==n){
            ListNode* temp=head->next;
            delete(head);
            return temp;
        }
        int travel_from_front=L-n;
        ListNode* temp=head;
        ListNode* prev=NULL;

        while(travel_from_front--){
           prev=temp;
            temp=temp->next;
        }

          prev->next=temp->next;
            delete(temp);
            return head;

    }
};