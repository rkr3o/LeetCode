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
    void reverse(ListNode* &head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        head = prev;
    }
    
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        
        reverse(head2);
        
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        
        while (temp1 != nullptr && temp2 != nullptr) {
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2->next;
            
            temp1->next = temp2;
            temp2->next = next1;
            
            temp1 = next1;
            temp2 = next2;
        }
    }
};
