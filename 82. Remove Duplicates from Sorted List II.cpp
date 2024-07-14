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
    ListNode* deleteDuplicates(ListNode* head) {
         // Step 1: Count the frequency of each node value
        std::unordered_map<int, int> freq;
        ListNode* curr = head;
        while (curr) {
            freq[curr->val]++;
            curr = curr->next;
        }
        
        // Step 2: Create a dummy node to help with the new linked list
        ListNode dummy(0);
        ListNode* newTail = &dummy;
        
        // Step 3: Traverse the list again and only keep distinct nodes
        curr = head;
        while (curr) {
            if (freq[curr->val] == 1) {
                newTail->next = new ListNode(curr->val);
                newTail = newTail->next;
            }
            curr = curr->next;
        }
        
        // Return the new linked list
        return dummy.next;
    }
};