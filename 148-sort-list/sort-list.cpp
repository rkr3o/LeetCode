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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        vector<int>list;
        while(head!=NULL)
        {
            list.push_back(head->val);
            head = head->next;
        }
        sort(list.begin(),list.end());
        ListNode* root = NULL;
        ListNode* temp = NULL;
        for(int i = 0 ; i < list.size() ; i++)
        {
            if(root==NULL)
            {
                root = new ListNode(list[i]);
                temp = root;
            }
            else
            {
                temp->next = new ListNode(list[i]);
                temp = temp->next;
            }
        }
        return root;
    }
};  