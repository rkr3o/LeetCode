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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>ans;
        for(int i = 0 ; i < lists.size() ; i++)
        {
            ListNode* root = lists[i];
            while(root!=NULL)
            {
                ans.push_back(root->val);
                root=root->next;
            }
        }
        sort(begin(ans),end(ans)); 
        //for(auto x : ans)cout<<x<<" ";
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(auto x : ans)
        {
            if(head==NULL)
            {
                head = new ListNode(x);
                tail=head;
            }
            else
            {
                tail->next=new ListNode(x);
                tail=tail->next;
            }
        }
        return head;
    }
};