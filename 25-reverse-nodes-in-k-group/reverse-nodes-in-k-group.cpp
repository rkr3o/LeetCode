 
class Solution {
public:
    int countNode(ListNode* head)
    {
        int cnt = 0 ;
        while(head)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = countNode(head);
        if(n<k)return head;
        //reverse first k half 
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next;
        int i = 0 ;
        while(cur!=NULL and  i < k)
        {
            next = cur->next;
            cur->next= prev;
            prev = cur;
            cur=next;
            i++;
        }
        if(next!=NULL)
        {
            head->next = reverseKGroup(next,k);
        }
        
        return prev;
       
    }
};