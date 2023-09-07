class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int x, int y) {
    if(x>=y || head==NULL )return head ;
     
     ListNode* dummy = new ListNode(0);
     dummy->next = head;
     
     ListNode* pre = dummy ; 
     for(int i = 0 ; i < x-1; i++)
     {
         pre = pre->next;
     }
    // cout<<pre->val<<endl;
     ListNode* start = pre->next;
     ListNode* end = start->next;
     for(int i = 0 ; i < y-x ; i++)
     {
         start->next = end->next;
         end->next = pre->next;
         pre->next = end;
         end = start->next;
     }
     return dummy->next;
   }
};