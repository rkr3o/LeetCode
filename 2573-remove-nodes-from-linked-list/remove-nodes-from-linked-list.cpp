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
    ListNode* reverseLL(ListNode* root)
    {
        if(root==NULL)return NULL;
        
        ListNode* cur = root;
        ListNode* prev = NULL;
        ListNode* next ;
        while(cur!=NULL)
        {
            next = cur->next;
            cur->next = prev ;
            prev = cur;
            cur=next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* reversedHead = reverseLL(head);
        ListNode* start = NULL;
       
        int maxi = INT_MIN;
        ListNode* curr = reversedHead;
        while(curr!=NULL)
        {
            if(maxi > curr->val)
            {
                start->next = curr->next;
            }
            else
            {
                maxi = curr->val;
                start = curr;
            }
            curr = curr->next;
        }
        return reverseLL(reversedHead);
    }
};