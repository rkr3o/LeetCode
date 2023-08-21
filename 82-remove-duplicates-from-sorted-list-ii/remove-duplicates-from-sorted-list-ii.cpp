class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* current = head;

        while (current) {
            bool isDuplicate = false;
            while (current->next && current->val == current->next->val) {
                current = current->next;
                isDuplicate = true;
            }

            if (isDuplicate) {
                prev->next = current->next;
            } else {
                prev = prev->next;
            }

            current = current->next;
        }

        return dummy->next;
    }
};
