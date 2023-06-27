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
    ListNode* sortList(ListNode* head) 
    {
        vector<int>st;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            st.push_back(temp->val);
            temp=temp->next;
        }
        sort(st.begin(),st.end());
        ListNode* top = NULL;
        ListNode* tail = NULL;
        for(int i = 0 ; i < st.size() ;i++)
        {
            if(!top)
            {
                top = new ListNode(st[i]);
                tail = top;
            }
            else
            {
                tail->next =  new ListNode(st[i]);
                tail = tail->next;
            }
        }
        return top;
    }
};