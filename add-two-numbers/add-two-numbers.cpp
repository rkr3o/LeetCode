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
        vector<int>a;
        vector<int>b;
        ListNode* temp = l1;
        ListNode* temp2 = l2;
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }
        while(temp2!=NULL)
        {
            b.push_back(temp2->val);
            temp2=temp2->next;
        }

        vector<int>ans;
        int n = a.size(), m = b.size();
        int i = 0 , j = 0 , carry = 0 ;
        while(i < a.size()  and j < b.size())
        {
            int sum = carry ;
            if(i<n)sum+=a[i++];
            if(j<m)sum+=b[j++];
            carry = sum/10;
            sum = sum%10;
            ans.push_back(sum);
        }
        while(i<n)
        {
            int sum = carry ;
            if(i<n)sum+=a[i++];
            carry = sum/10;
            sum = sum%10;
            ans.push_back(sum);
        }
        while(j<m)
        {
            int sum = carry ;
            if(j<m)sum+=b[j++];
            carry = sum/10;
            sum = sum%10;
            ans.push_back(sum);
        }
        if(carry)ans.push_back(carry);
        ListNode* newHead = new ListNode(0);
        ListNode* cur = newHead;
        for(int i = 0 ; i < ans.size() ; i++)
        {
            cur->next = new ListNode(ans[i]);
            cur = cur->next;
        }
        ListNode* resultHead = newHead->next;
        delete newHead;
        return resultHead;

    }
};