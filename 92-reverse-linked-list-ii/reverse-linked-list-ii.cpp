class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int x, int y) {
    vector<int> list;
    while (head != NULL) {
        list.push_back(head->val);
        head = head->next;
    }
    reverse(list.begin() + x - 1, list.begin() + y); // Fixed range for reverse
    ListNode* root = NULL;
    ListNode* tail = NULL;
    for (int i = 0; i < list.size(); i++) {
        if (root == NULL) {
            root = new ListNode(list[i]);
            tail = root;
        } else {
            tail->next = new ListNode(list[i]);
            tail = tail->next;
        }
    }
    return root;
   }
};