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
    int getSize(ListNode* root) {
        if (root == nullptr) return 0;
        return 1 + getSize(root->next);
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left >= right) return head;

        int n = getSize(head);

        // Create a dummy node to simplify handling of edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Move prev to the node before the left-th node
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // Reverse the sublist between left and right
        ListNode* current = prev->next;
        ListNode* tail = current;  // The last node of the reversed sublist
        ListNode* next;

        for (int i = left; i <= right; ++i) {
            next = current->next;
            current->next = prev->next;
            prev->next = current;
            current = next;
        }

        tail->next = current;  // Connect the reversed sublist with the rest of the list

        return dummy.next;
    }
};
