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
         ListNode *temp = head, *prev = head;
        // Traverse list till the last node
        while (temp != NULL) {
            // Compare values of both pointers
            if (temp->val != prev->val) {
                // if the value of prev is not equal to the
                // value of temp that means there are no more
                // occurrences of the prev data-> So we can set
                // the next of prev to the temp node->*/
                prev->next = temp;
                prev = temp;
            }
            // Set the temp to the next node
            temp = temp->next;
        }
        // This is the edge case if there are more than one
        // occurrences of the last element
        if (prev != temp)
            prev->next = NULL;
        return head;
    }
};