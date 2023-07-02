/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        void reverse(ListNode* &head)
        {
            if (head == nullptr || head->next == nullptr)
            {
                return;
            }

            ListNode *prev = nullptr;
            ListNode *cur = head;
            ListNode *next = nullptr;

            while (cur != nullptr)
            {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            head = prev;
        }

    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
       	//find mid element and reverseve those elements and simple add it 
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL and fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = head;
        ListNode *head2 = slow->next;
        slow->next = NULL;
        reverse(head2);

        ListNode *temp1 = NULL;
        ListNode *temp2 = NULL;
        while (head2 != NULL)
        {
            temp1 = head1->next;
            temp2 = head2->next;
            head1->next = head2;
            head2->next = temp1;

            head1 = temp1;
            head2 = temp2;
        }
    }
};