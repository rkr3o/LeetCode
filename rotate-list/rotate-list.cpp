class Solution {
public:
    int getSize(ListNode* head) {
        int cnt = 0;
        while (head != nullptr) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return head;

        int n = getSize(head);
        int req = k % n;

        if (req == 0)
            return head;

        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head;

        int cnt = 0;
        while (cnt != n - req-1) {
            head = head->next;
            cnt++;
        }
        ListNode* newHead = head->next;
        head->next = nullptr;
        return newHead;
    }
};
