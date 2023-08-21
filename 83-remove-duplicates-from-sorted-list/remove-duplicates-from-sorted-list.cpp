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
        if (head == nullptr || head->next == nullptr) {
            return head; // No duplicates possible
        }
    
        unordered_set<int> uniqueValues;
        ListNode *current = head;
        ListNode *prev = nullptr;
    
        while (current != nullptr) {
            if (uniqueValues.find(current->val) != uniqueValues.end()) {
                // Duplicate found, remove the current node
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                // New unique value, add it to the set and move pointers
                uniqueValues.insert(current->val);
                prev = current;
                current = current->next;
            }
        }
    
        return head;
    }
};