class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Check for edge cases
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* dummy = new ListNode(0); // Dummy node to simplify the code
        dummy->next = list1; // Set the dummy's next to the first node of list1
        ListNode* prev = dummy; // Pointer to the previous node

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                prev = list1; // Move the prev pointer
                list1 = list1->next; // Move the list1 pointer
            } else {
                prev->next = list2; // Update the next pointer of prev
                list2 = list2->next; // Move the list2 pointer
                prev = prev->next; // Move the prev pointer
                prev->next = list1; // Update the next pointer of prev
            }
        }

        if (list2 != NULL) {
            prev->next = list2; // Attach the remaining nodes from list2
        }

        return dummy->next; // Skip the dummy node and return the merged list
    }
};
