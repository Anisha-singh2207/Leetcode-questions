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
    ListNode* removeZeroSumSublists(ListNode* head) {
          int prefixSum = 0;
        unordered_map<int, ListNode*> mp;
        ListNode* dummyNode = new ListNode(0); 
        dummyNode->next = head;
        mp[0] = dummyNode;

        while (head != nullptr) {
            prefixSum += head->val;

            if (mp.find(prefixSum) != mp.end()) {
                // Found a matching prefix sum, which means there is a zero-sum sublist
                ListNode* start = mp[prefixSum];  // Get the node where prefixSum was seen
                ListNode* temp = start->next;
                int pSum = prefixSum;

                // Traverse through the nodes between start and head, and erase their prefix sums
                while (temp != head) {
                    pSum += temp->val;  // Keep updating the prefix sum
                    mp.erase(pSum);     // Erase this prefix sum from the map
                    temp = temp->next;
                }

                // Connect the start node to the node right after the current head
                start->next = head->next;
            } else {
                // If the prefix sum is not in the map, store the current node
                mp[prefixSum] = head;
            }

            // Move to the next node
            head = head->next;
        }

        return dummyNode->next; 
    }
};