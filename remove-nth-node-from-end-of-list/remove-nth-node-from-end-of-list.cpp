class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); // for handling the case of deletion of node head
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move the fast pointer n nodes ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both pointers until the fast pointer reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the node pointed by the slow pointer
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        ListNode* result = dummy->next;
        delete dummy;
        
        return result;
    }
};
