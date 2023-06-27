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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL and l2==NULL)return NULL;
        if(l1==NULL and l2!=NULL)return l2;
        if(l1!=NULL and l2==NULL)return l1;
        
        ListNode* tail = NULL;
        ListNode* head = NULL;
        int carry = 0;
        while(l1!=NULL ||  l2!=NULL || carry)
        {
            int sum = carry;
            if(l1)
            {
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            sum = sum%10;

            ListNode* newNode = new ListNode(sum);
            if(!head)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail=tail->next;
            }
        }
        return head;
    }
};