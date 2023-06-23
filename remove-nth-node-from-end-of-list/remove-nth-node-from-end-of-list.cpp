class Solution {
public:
    int getSize(ListNode* head)
    {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        
        // Handle case when the node to be removed is the head node
        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        ListNode* temp = head;
        int req = size - n - 1;
        int cnt = 0;
        
        while (cnt < req )
        {
            cnt++;
            temp = temp->next;
        }
        
        ListNode* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
        
        return head;
    }
};
