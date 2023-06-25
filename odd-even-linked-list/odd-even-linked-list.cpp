class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if(head->next==NULL)return head;
        vector<int> nodes;
        ListNode* current = head;
        while (current != nullptr) {
            nodes.push_back(current->val);
            current = current->next;
        }

        vector<int> odd, even;
        for (int i = 0; i < nodes.size(); i++) {
            if ((i+1) % 2 == 0) {
                even.push_back(nodes[i]);
            } else {
                odd.push_back(nodes[i]);
            }
        }

        ListNode* new_head = new ListNode(odd[0]);
        ListNode* curr = new_head;
        for (int i = 1; i < odd.size(); i++) {
            curr->next = new ListNode(odd[i]);
            curr = curr->next;
        }

        curr->next = new ListNode(even[0]);
        curr = curr->next;
        for (int i = 1; i < even.size(); i++) {
            curr->next = new ListNode(even[i]);
            curr = curr->next;
        }

        return new_head;
    }
};
