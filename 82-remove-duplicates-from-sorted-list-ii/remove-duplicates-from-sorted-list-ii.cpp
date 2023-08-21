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
        set<int>st;
        vector<int>ans;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        for(int i =1; i < ans.size(); i++)
        {
            if(ans[i]==ans[i-1])
            {
                st.insert(ans[i]);
            }
        }
        ListNode* newNode = NULL;
        ListNode* tail = NULL;
        while(head!=NULL)
        {
            if(st.find(head->val)==st.end())
            {
                if(newNode==NULL)
                {
                    newNode = new ListNode(head->val);
                    tail = newNode;
                }
                else
                {
                    tail->next=  new ListNode(head->val);
                    tail=tail->next;
                }
            }
            head = head->next;
        }
        return newNode;
    }
};