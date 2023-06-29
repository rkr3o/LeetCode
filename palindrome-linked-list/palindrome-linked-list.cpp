 
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
    
        while(cur!=NULL)
        {
            ListNode* next   = cur->next;
            cur->next = prev;
            prev = cur ;
            cur =next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        //find middle element
        ListNode* slow = head ;
        ListNode* fast = head ;
        int i = 0 ;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;  
        }
        //reverse second half
        ListNode* second = reverse(slow);
        ListNode* curr = head;
        while (second != nullptr) {
            if (curr->val != second->val) {
                return false;
            }
            curr = curr->next;
            second = second->next;
        }
        return true;
    }
};